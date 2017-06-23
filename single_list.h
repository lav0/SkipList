//
//  single_list.h
//  skip_list
//
//  Created by Andrey on 27.05.17.
//  Copyright © 2017 Andrey. All rights reserved.
//
#pragma once
#include "operations.h"
#include "head.h"
#include <cassert>
#include <iostream>

namespace sl {
    
    class single_list
    {
    public:
        single_list(head* h) : h_(h) { assert(nullptr != h_); }
        single_list(item* i)
        {
            item* left = i;
            while (nullptr != left->get_prev())
                left = left->get_prev();

            h_ = dynamic_cast<head*>(left);
        }
        
        bool insert(item* new_item)
        {
            assert(nullptr != h_);
            assert(nullptr != new_item);
            
            new_item->set_next(nullptr);
            new_item->set_prev(nullptr);
            
            item* walker = h_;
            while (nullptr != walker)
            {
                if (nullptr == walker->get_next())
                {
                    hori_join(walker, new_item);
                    return true;
                }
                
                auto next = walker->get_next();
                
                if (*new_item < *next)
                {
                    hori_join(walker, new_item);
                    hori_join(new_item, next);
                    return true;
                }
                
                walker = walker->get_next();
            }
            
            return false;
        }
        
        head* get_head() const { assert(nullptr != h_); return h_; }
        item* get_tail() const
        {
            assert(nullptr != h_);
            item* tail = h_;
            while (nullptr != tail->get_next())
                tail = tail->get_next();
            return tail;
        }
        
        void to_stream() const
        {
            assert(nullptr != h_);
            auto walker = h_->get_next();
            while (nullptr != walker)
            {
                std::cout << walker->get_value() << ' ';
                walker = walker->get_next();
            }
            std::cout << '\n';
        }
        
    private:
        
        head* h_ = nullptr;
    };
}
