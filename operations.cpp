#include "operations.h"

//using namespace sl;

bool sl::hori_join(item* left, item* right)
{
  left->set_next(right);
  right->set_prev(left);

  return true;
}

bool sl::vert_join(item* bottom, item* up)
{
  bottom->set_over(up);
  up->set_under(bottom);

  return true;
}

bool sl::not_equal(item* first, item* second)
{
  return (*first < *second) || (*second < *first);
}

bool sl::equal(item* first, item* second)
{
  return !not_equal(first, second);
}

// The output is whether equal or greater than the wanted
bool sl::find_forward(item* pivot, item* to_find, item** output)
{
  assert(nullptr != pivot);
  assert(nullptr != to_find);
  assert(nullptr != output);
  assert(*pivot < *to_find);

  *output = nullptr;

  auto walker = pivot;
  while (walker != nullptr)
  {
    if (!(*walker < *to_find))
    {
      *output = walker;
      return true;
    }

    walker = walker->get_next();
  }

  return false;
}
bool sl::find_backward(item* pivot, item* to_find, item** output)
{
  assert(nullptr != pivot);
  assert(nullptr != to_find);
  assert(nullptr != output);
  assert(*to_find < *pivot);

  *output = nullptr;

  auto walker = pivot;
  while (walker != nullptr)
  {
    if (!(*to_find < *walker))
    {
      *output = walker;
      return true;
    }

    walker = walker->get_prev();
  }

  return false;
}