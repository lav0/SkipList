//
//  main.cpp
//  skip_list
//
//  Created by Andrey on 27.05.17.
//  Copyright © 2017 Andrey. All rights reserved.
//

#include "skip_list.h"
#include "platform_spec.h"

using namespace sl;

using the_type = int;


bool test_find()
{
  /*head h1, h2, h3;

  item it31(3), it32(3), it33(3);
  item it5(5);
  item it71(7), it72(7);

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

  skip_list list (&h1);*/
    skip_list list;

    list.insert(3);
    list.insert(5);
    list.insert(7);

    item * p1 = nullptr, *p2 = nullptr, *p3 = nullptr, *p4 = nullptr;

    bool b1 = list.find(5, &p1);
    bool b2 = list.find(6, &p2);
    bool b3 = list.find(7, &p3);
    bool b4 = list.find(3, &p4);

    list.to_stream();

    return
        b1 == true &&
        b2 == false &&
        b3 == true &&
        b4 == true &&
        p1 == p2 &&
        p3 == single_list(list.get_base_head()).get_tail() &&
        p1->get_under() == nullptr &&
        p2->get_under() == nullptr &&
        p3->get_under() == nullptr &&
        p4->get_under() == nullptr;
}

bool test_gen()
{
    skip_list list;

    list.insert(3);
    list.insert(5);
    list.insert(7);
    list.to_stream();

    list.insert(4);

    auto bhead = list.get_base_head();

    bool b = bhead->get_next()->get_next()->get_value() == 4;

    int counter = 0;
    while (nullptr != bhead)
    {
        ++counter;
        bhead = dynamic_cast<head*>(bhead->get_above());
    }

    b &= counter <= 4;

    return b;
}

int main(int argc, const char * argv[]) {
    
    bool test = true;

    test &= test_find();
    std::cout << '\n';
    test &= test_gen();
    
    if (!test)
        output_failed_result();
    else
        std::cout << "Tests passed\n";
    
    return 0;
}
