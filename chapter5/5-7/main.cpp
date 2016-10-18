#include <iostream>
#include <string>
#include <vector>
#include "frame.h"
#include "width.h"

int main()
{
  std::vector<std::string> v;
    std::vector<std::string> f = frame(v);

  for (std::vector<std::string>::size_type i = 0; i != f.size(); ++i)
    std::cout << f[i] << std::endl;

  return 0;
}
