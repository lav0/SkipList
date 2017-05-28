//
//  main.cpp
//  skip_list
//
//  Created by Andrey on 27.05.17.
//  Copyright © 2017 Andrey. All rights reserved.
//

#include <iostream>
#include "skip_list.h"

using namespace sl;

using the_type = int;

int main(int argc, const char * argv[]) {
    
    head h1, h2, h3;
    
    item it31(3), it32(3), it33(3);
    item it5(5), it5_find(5);
    item it71(7), it72(7);
    item it6(6);
    
    vert_join(&h1, &h2);
    vert_join(&h2, &h3);
    vert_join(&it31, &it32);
    vert_join(&it32, &it33);
    vert_join(&it71, &it72);
    
    hori_join(&h1, &it31);
    hori_join(&h2, &it32);
    hori_join(&h3, &it33);
    
    hori_join(&it31, &it5);
    
    hori_join(&it5, &it71);
    hori_join(&it32, &it72);
    
    skip_list list(&h1);
    list.to_stream();
    
    std::cout << "Hello, World!\n";
    return 0;
}
