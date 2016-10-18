#include <iostream>
#include <string>
#include <vector>
#include "hcat.h"
#include "split.h"
#include "width.h"

int main()
{

  std::string s1 = "the quick brown fox jumps over the lazy";
  std::string s2 = "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG";

  std::vector<std::string> ss1 = split(s1);
  std::vector<std::string> ss2 = split(s2);

  std::vector<std::string> cat = hcat(ss1, ss2);

  for (std::vector<std::string>::size_type i = 0; i != cat.size(); ++i) {
    std::cout << cat[i] << std::endl;
  }

  return 0;
}
