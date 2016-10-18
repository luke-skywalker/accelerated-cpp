#include <algorithm>
#include <iostream>
#include <string>

bool is_palindrome(const std::string& s)
{
  return std::equal(s.begin(), s.end(), s.rbegin());
}

int main()
{
  std::cout << is_palindrome("madam") << std::endl;
}
