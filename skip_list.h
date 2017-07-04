//
//  skip_list.h
//  skip_list
//
//  Created by Andrey on 28.05.17.
//  Copyright © 2017 Andrey. All rights reserved.
//
#pragma once

#include "single_list.h"
#include "Randomler.h"

namespace sl {
    
    class skip_list
    {
    public:
        
        skip_list();
        skip_list(head* h);
        ~skip_list();
        
        /*
         *   true if exact match is found
         *   output is always set
         */
        bool find(const item::T& new_value, item** output);
        
        bool insert(const item::T& new_value);
        
        void to_stream() const;

        head* get_base_head() const { return base_head_; }

    private:

        bool find(item* new_item, item** output);
        bool insert(item* new_item);
        bool insert_after_one_layer(item* after, item* new_item);
        bool insert_into_layer_over(head* current, item* to_insert);

      /**
       * \brief returns the head of the most high and sparse list
       * \return 
       */
        head* highest_head() const;
        item* first_left_with_above_item(item* from_this) const;

    private:
        
        head* base_head_ = nullptr;

        randomler<item::T> tough_rand;
    };
}
