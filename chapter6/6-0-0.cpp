#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// true if argument is whitespace, false otherwise
bool space(char c)
{
  return isspace(c);
}

// false if the argument is whitespace, true otherwise
bool not_space(char c)
{
  return !isspace(c);
}

std::vector<std::string> split(const std::string& str)
{
  typedef std::string::const_iterator iter;
  std::vector<std::string> ret;

  iter i = str.begin();
  while (i != str.end()) {

    // ignore leading blanks
    i = find_if(i, str.end(), not_space);

    // find end of next word
    iter j = find_if(i, str.end(), space);

    // copy the characters in [i, j)
    if (i != str.end())
      ret.push_back(std::string(i, j));
    i = j;
  }
  return ret;
}

int main()
{
  std::vector<std::string> v = split("This is a test sentence");

  for (std::vector<std::string>::size_type i = 0; i != v.size(); ++i) {
    std::cout << v[i] << std::endl;
  }
}
