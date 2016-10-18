// find all the lines that refer to each word in the input

#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>
#include "split.h"

std::map<std::string, std::vector<int> >
  xref (std::istream& in,
        std::vector<std::string> find_words(const std::string&) = split)
{
  std::string line;
  int line_number = 0;
  std::map<std::string, std::vector<int> > ret;

  // read the next line
  while (getline(in, line)) {
    ++line_number;

    // break the input line into words
    // (return a vector of strings)
    std::vector<std::string> words = find_words(line);

    // remember that each word occurs on the current line
    for (std::vector<std::string>::const_iterator it = words.begin();
	 it != words.end(); ++it){
      // do we already have this line_number for this word? if not, add it!
      if (!(std::find(ret[*it].begin(), ret[*it].end(), line_number) != ret[*it].end()))
	ret[*it].push_back(line_number);
    }
  }
  return ret;
}
