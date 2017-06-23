//
//  skip_list.cpp
//  skip_list
//
//  Created by Andrey on 28.05.17.
//  Copyright © 2017 Andrey. All rights reserved.
//

#include "skip_list.h"
#include <random>
#include <chrono>

using namespace sl;


skip_list::skip_list(head* h) : base_head_(h) { }

bool skip_list::find(item* new_item, item** output)
{
    head* cur_head = highest_head();
    item* cur_pivot = cur_head;
    bool go_right = true;
    
    while (not_equal(cur_pivot, new_item))
    {
        item* new_pivot = nullptr;
        bool pivot_found = false;
        if (go_right)
        {
            pivot_found =
            find_forward(cur_pivot, new_item, &new_pivot);
        }
        else
        {
            pivot_found =
            find_backward(cur_pivot, new_item, &new_pivot);
        }
        
        if (pivot_found)
        {
            cur_pivot = new_pivot;
            go_right = !go_right;
        }
        else
        {
            assert(go_right);
            
            single_list single(cur_head);
            cur_pivot = single.get_tail();
        }
        
        if (nullptr == cur_pivot->get_under())
        {
            assert(nullptr == cur_head->get_under());
            break;
        }
        
        cur_pivot = cur_pivot->get_under();
        cur_head = dynamic_cast<head*>( cur_head->get_under() );
        
    }
    
    while (nullptr != cur_pivot->get_under())
        cur_pivot = cur_pivot->get_under();
    
    *output = cur_pivot;
    
    return equal(cur_pivot, new_item);
}

bool yes_or_no()
{
    std::default_random_engine rand_engine;
    rand_engine.seed(
        static_cast<unsigned long>(
            std::chrono::high_resolution_clock::now().time_since_epoch().count()
        )
    );

    std::uniform_int_distribution<item::T> distributor(0, 1);

    auto val = distributor(rand_engine);
    bool res = val % 2 == 1;
    
        std::cout << "--> " << val << "\n";
   
    return res;
}

bool skip_list::insert(item* new_item)
{
    item* pivot = nullptr;
    find(new_item, &pivot);

    item* to_insert = new_item;
    item::T value = new_item->get_value();
    bool new_head_created = false;
    bool need_insertion = true;
    while (need_insertion)
    {
        insert_after_one_layer(pivot, to_insert);

        if (new_head_created)
            break;

        if (need_insertion = yes_or_no())
        {
            auto ledder = first_left_with_above_item(pivot);
            if (nullptr == ledder)
            {
                single_list slist(pivot);
                auto this_head = slist.get_head();

                assert(nullptr == this_head->get_above());

                auto new_head = new head;
                vert_join(this_head, new_head);
                new_head_created = true;

                ledder = this_head;
            }

            pivot = ledder->get_above();

            auto item_tmp = new item(value);
            vert_join(to_insert, item_tmp);
            to_insert = item_tmp;
        }
    }

    return true;
}

bool skip_list::insert_after_one_layer(item* after_me, item* new_item)
{
  assert(nullptr != after_me);
  assert(nullptr != new_item);

  auto next = after_me->get_next();

  hori_join(after_me, new_item);
  if (nullptr != next)
  {
    hori_join(new_item, next);
  }

  return true;
}

bool skip_list::insert_into_layer_over(head* current, item* to_insert)
{
  auto head_over = dynamic_cast<head*>(current->get_above());

  if (nullptr == head_over)
  {
    head_over = new head;
    vert_join(current, head_over);
  }

  single_list single(head_over);

  return single.insert(to_insert);;
}

void skip_list::to_stream() const
{
  auto h = highest_head();

  while (nullptr != h)
  {
    single_list single(h);
    single.to_stream();
    h = dynamic_cast<head*>(h->get_under());
  }
}

head* skip_list::highest_head() const
{
  item* h = base_head_;
  while (nullptr != h->get_above())
    h = h->get_above();
  return dynamic_cast<head*>(h);
}

item* skip_list::first_left_with_above_item(item* from_this) const
{
  assert(nullptr != from_this);

  item* left = from_this;
  while (nullptr == left->get_above())
  {
    left = left->get_prev();
    if (nullptr == left)
      return nullptr;
  }

  return left;
}
