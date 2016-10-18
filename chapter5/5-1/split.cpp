// this function splits a string everywhere there's a space.
// every individual word is pushed as an element of a vector

#include <cctype>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string& s)
{
  std::vector<std::string> ret;
  typedef std::string::size_type string_size;
  string_size i = 0;

  // invariant: we have processed characters [original value of i, i)
  while (i != s.size()) {
    // ignore leading blanks
    // invariant: characters in range [original i, current i) are all spaces
    while (i != s.size() && std::isspace(s[i]))
      ++i;

    // find end of next words
    string_size j = i;
    // invariant: none of the characters in range [original j, current j) is a space
    while (j != s.size() && !std::isspace(s[j]))
      j++;
    // if we found some nonwhitespace characters
    if (i != j) {
      // copy from s starting at i and taking j - i chars
      ret.push_back(s.substr(i, j - i));
      i = j;
    }
  }
  return ret;
}
