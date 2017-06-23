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
        
        void to_stream() const;

        head* get_base_head() const { return base_head_; }

    private:

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
    };
}
