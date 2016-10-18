#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

void display_vector(std::vector<int> v)
{
  std::vector<int>::const_iterator cit;
  if (v.empty())
    std::cout << "The vector is empty!" << std::endl;
  for (cit = v.begin(); cit != v.end(); ++cit)
    std::cout << *cit << std::endl;
}

int main()
{
  // construct the container with 10 copies of elements with value 100
  std::cout << std::endl << "ORIGINAL VECTOR" << std::endl;
  std::vector<int> u(10,100);
  display_vector(u);

  // this will not work because v has size 0
  //
  // std::vector<int> v;
  // copy(u.begin(), u.end(), v.begin());

  // there are two fixes:
  // 1. construct the container with the content of an existing range of the same size
  std::cout << std::endl << "FIX 1" << std::endl;
  std::vector<int> v(u.begin(), u.end());
  copy(u.begin(), u.end(), v.begin());
  display_vector(v);

  // 2. use an iterator adaptor instead of an iterator
  std::cout << std::endl << "FIX 2" << std::endl;
  v.clear();
  display_vector(v);
  copy(u.begin(), u.end(), back_inserter(v));
  display_vector(v);

  return 0;
}
