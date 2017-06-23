//
//  item.h
//  skip_list
//
//  Created by Andrey on 27.05.17.
//  Copyright © 2017 Andrey. All rights reserved.
//

#pragma once

namespace sl
{
    class item
    {
    public:
        
        using it = item;
        using T = int;
        
        item(const T& value) : value_(value) {}
        
        virtual bool is_head() const { return false; }
        virtual bool operator<(const it& p) const { return value_ < p.value_; }
        
        virtual void set_next(it* p) { next_ = p; }
        virtual void set_prev(it* p) { prev_ = p; }
        virtual void set_over(it* p) { over_ = p; }
        virtual void set_under(it* p) { under_ = p; }
        
        it* get_next() const { return next_; }
        it* get_prev() const { return prev_; }
        it* get_above() const { return over_; }
        it* get_under() const { return under_; }        
        
        const T& get_value() const { return value_;}
        
    protected:
        
        it* next_ = nullptr;
        it* prev_ = nullptr;
        it* over_ = nullptr;
        it* under_ = nullptr;
        
        T value_;
        
    };
}
