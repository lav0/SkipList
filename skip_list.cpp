//
//  skip_list.cpp
//  skip_list
//
//  Created by Andrey on 28.05.17.
//  Copyright © 2017 Andrey. All rights reserved.
//

#include "skip_list.h"

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

bool skip_list::insert(item* new_item)
{
    
    
//    if (nullptr == cur_head->get_under())
//    {
//        single_list single(cur_head);
//        single.insert(new_item);
//        
//        if (/* probability */ nullptr != new_item->get_next())
//        {
//            auto new_copy = new item(new_item->get_value());
//            insert_into_layer_over(cur_head, new_copy);
//        }
//    }
    
    return false;
}
