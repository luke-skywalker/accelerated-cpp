#include <algorithm>
#include <iterator>
#include <list>
#include <string>
#include <iostream>
#include "split_to_list.h"

bool is_palindrome(std::string& s)
{
  std::string reverse;
  for (std::string::reverse_iterator iter = s.rbegin(); iter != s.rend(); ++iter) {
    reverse.push_back(*iter);
  }
  if (s == reverse)
    return true;
  else
    return false;
}

int main()
{
  std::string s = "ANANA almost ananas the pineapple CIVIC Pertaining to cities "
    "LEVEL To even out MADAM A term of address for women";

  std::list<std::string> l = split_to_list(s);


  std::string::size_type maxlen = 0;
  std::list<std::string> palindromes;
  std::list<std::string>::iterator iter = l.begin();
  while (iter != l.end()) {
    if (is_palindrome(*iter)) {
      palindromes.push_back(*iter);
      maxlen = std::max(maxlen, iter->size());
    }
    ++iter;
  }

  iter = palindromes.begin();
  while (iter != palindromes.end()) {
    std::cout << *iter << std::endl;
    ++iter;
  }

  std::cout << "Longest palindrome: " << maxlen << " characters." << std::endl;

  return 0;
}
