// concatenate all the elements of a vector<string> in a string

#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int main()
{
  // read strings
  std::string s;
  std::vector<std::string> v;
  while (std::cin >> s)
    v.push_back(s);

  // concatenate them
  std::string cat = std::accumulate(v.begin(), v.end(), std::string(""));

  std::cout << cat << std::endl;

  return 0;
}
