//
//  operations.h
//  skip_list
//
//  Created by Andrey on 27.05.17.
//  Copyright © 2017 Andrey. All rights reserved.
//
#pragma once

#include "item.h"
#include <cassert>

namespace sl {
    
  bool hori_join(item* left, item* right);
    
  bool vert_join(item* bottom, item* up);
    
  bool not_equal(item* first, item* second);
    
  bool equal(item* first, item* second);
    
    // The output is whether equal or greater than the wanted
  bool find_forward(item* pivot, item* to_find, item** output);
  bool find_backward(item* pivot, item* to_find, item** output);
}
