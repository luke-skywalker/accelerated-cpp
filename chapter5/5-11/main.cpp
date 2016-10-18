#include <algorithm>
#include <iterator>
#include <string>
#include <iostream>

// maybe more readable with a for loop, but I want to practise while loops!
bool contains_chars(const std::string& word, const std::string& chars)
{
  std::string::const_iterator cit_word = word.begin();
  std::string::const_iterator cit_chars;
  while (cit_word != word.end()) {
    cit_chars = chars.begin();
    while (cit_chars != chars.end()) {
      if (*cit_word == *cit_chars)
	return true;
      ++cit_chars;
    }
    ++cit_word;
  }
  return false;
}

int main()
{
  std::string scenders = "bdfhkltgjpqy";

  std::string s;
  std::string longest;
  std::string::size_type longest_sz = 0;
  while (std::cin >> s) {
    std::cout << std::endl;
    // does it contain scenders?
    if (contains_chars(s, scenders))
      std::cout << s << " contains {a|de}scenders!" << std::endl;
    else
      // is it the longest without scenders we found?
      if (s.size() > longest.size())
	longest = s;
    std::cout << "Longest word without {a|de}scenders so far: " << longest << std::endl;
  }

  return 0;
}
