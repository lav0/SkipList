//
//  head.h
//  skip_list
//
//  Created by Andrey on 27.05.17.
//  Copyright © 2017 Andrey. All rights reserved.
//
#pragma once

#include "item.h"

namespace sl {
    
    class head : public item
    {
    public:
        
        head() : item(0) { prev_ = nullptr; }
        
        bool is_head() const override { return true; }
        bool operator<(const it& p) const override { return true; }
        
        void set_prev(it* p) override {}
    };
    
}
