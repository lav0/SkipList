//
//  skip_list.h
//  skip_list
//
//  Created by Andrey on 28.05.17.
//  Copyright © 2017 Andrey. All rights reserved.
//
#pragma once

#include "single_list.h"

namespace sl {
    
    class skip_list
    {
    public:
        
        skip_list(head* h);
        
        /*
         *   true if exact match is found
         *   output is always set
         */
        bool find(item* new_item, item** output);
        
        bool insert(item* new_item);
        
        void to_stream() const
        {
            auto h = highest_head();
            
            while (nullptr != h)
            {
                single_list single(h);
                single.to_stream();
                h = dynamic_cast<head*>(h->get_under());
                std::cout << '\n';
            }
        }

    private:
        
        bool insert_into_layer_over(head* current, item* to_insert)
        {
            auto head_over = dynamic_cast<head*>(current->get_over());
            
            if (nullptr == head_over)
            {
                head_over = new head;
                vert_join(current, head_over);
            }
            
            single_list single(head_over);
            
            single.insert(to_insert);
            
            return false;
        }
        
        head* highest_head() const
        {
            item* h = base_head_;
            while (nullptr != h->get_over())
                h = h->get_over();
            return dynamic_cast<head*>(h);
        }
        
    private:
        
        head* base_head_ = nullptr;
    };
}
