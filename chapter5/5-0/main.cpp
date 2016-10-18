#include <iostream>
#include <string>
#include <vector>
#include "frame.h"
#include "split.h"
#include "width.h"
#include "vcat.h"
#include "hcat.h"

int main()
{
  // testing the split function
  std::cout << std::endl << "### testing split.cpp ###" << std::endl;
  std::string s = "This is an example to illustrate framing";
  std::vector<std::string> ss;
  ss = split(s);

  std::vector<std::string>::const_iterator iter = ss.begin();
  while(iter != ss.end()) {
    std::cout << *iter << std::endl;
    ++iter;
  }

  // testing the width function
  std::cout << std::endl << "### testing width.cpp ###" << std::endl;
  std::cout << width(ss) << std::endl;

  // testing the frame function
  std::cout << std::endl << "### testing frame.cpp ###" << std::endl;
  std::vector<std::string> f = frame(ss);
  iter = f.begin();
  while(iter != f.end()) {
    std::cout << *iter << std::endl;
    ++iter;
  }

  // testing the vcat function
  std::cout << std::endl << "### testing vcat.cpp ###" << std::endl;
  std::vector<std::string> vc = vcat(f, ss);
  iter = vc.begin();
  while(iter != vc.end()) {
    std::cout << *iter << std::endl;
    ++iter;
  }

  // testing the hcat function
  std::cout << std::endl << "### testing hcat.cpp ###" << std::endl;
  std::vector<std::string> hc = hcat(f, ss);
  iter = hc.begin();
  while(iter != hc.end()) {
    std::cout << *iter << std::endl;
    ++iter;
  }


  return 0;
}
