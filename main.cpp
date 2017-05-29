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
  head h1, h2, h3;

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

  skip_list list (&h1);

  item it5_find(5), it6(6), it7_find(7), it3_find(3);

  item * p1 = nullptr, *p2 = nullptr, *p3 = nullptr, *p4 = nullptr;

  bool b1 = list.find(&it5_find, &p1);
  bool b2 = list.find(&it6, &p2);
  bool b3 = list.find(&it7_find, &p3);
  bool b4 = list.find(&it3_find, &p4);

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

int main(int argc, const char * argv[]) {
    
  bool test = true;

  test &= test_find();

  if (!test)
    output_failed_result();
  else
    std::cout << "Tests passed\n";
    
    return 0;
}
