#include <iostream>
#include <string>
#include <vector>
#include "center.h"
#include "split.h"

int main()
{
  std::string s = "The quick brown fox jumps over the lazy dog";
  std::vector<std::string> v = split(s);

  std::vector<std::string> v_center = center(v);

  for (std::vector<std::string>::size_type i = 0; i != v_center.size(); ++i)
    std::cout << v_center[i] << std::endl;

  return 0;
}
