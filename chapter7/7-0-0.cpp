// a simple counting words program

#include <iostream>
#include <iterator>
#include <map>
#include <string>

int main()
{
  std::string s;
  // store each word and an associated counter
  std::map<std::string, int> counter;

  // read the input, keeping track of each word and how often we see it
  while (std::cin >> s)
    ++counter[s];

  // write the words and the associated counts
  for (std::map<std::string, int>::const_iterator it = counter.begin();
       it != counter.end(); ++it) {
    std::cout << it->first << " appears "
	      << it->second << " times" << std::endl;
  }

  return 0;
}
