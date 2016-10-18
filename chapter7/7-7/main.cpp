/*
  same as 7-0-3, but xref is modified:

  * not to output multiple occurrences on the same line as repeated
  * to write "line" or "lines" appropriately

*/



#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "xref.h"

int main()
{
  // call xref using split by default
  std::map<std::string, std::vector<int> > ret = xref(std::cin);

  // write the results

  for (std::map<std::string, std::vector<int> >::const_iterator it = ret.begin();
       it != ret.end(); ++it) {

    // write the word
    if (it->second.size() == 1)
      std::cout << it->first << " occurs on line: ";
    else
      std::cout << it->first << " occurs on lines: ";

    // followed by one or more line numbers
    std::vector<int>::const_iterator line_it = it->second.begin();
    std::cout << *line_it;        // write the first line number

    ++line_it;
    // write the rest of the line numbers, if any
    while (line_it != it->second.end()) {
      std::cout << ", " << *line_it;
      ++line_it;
    }
    // write a new line to separate each word from the next
    std::cout << std::endl;
  }
  return 0;
}
