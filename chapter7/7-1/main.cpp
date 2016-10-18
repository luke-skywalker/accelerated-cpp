// same as 7-0-1, but produces output sorted by occurrence count and
// details the number of occurrences per line as well

#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>
#include "entry.h"
#include "xref.h"

int main()
{
  // call xref using split by default
  std::map<std::string, std::vector<int> > ret = xref(std::cin);

  // put all the recorded words in a list
  std::list<entry> entries = map_to_structs(ret);

  // order the words per appearence
  entries.sort(occurrence_sort);

  // print the results
  std::list<entry>::const_iterator w = entries.begin();
  while (w != entries.end()) {
    std::cout << std::endl
	      << w->word << " appears " << w->tot_count << " time(s)."
	      << std::endl;
    for (std::map<int, int>::const_iterator n = w->count.begin();
	 n != w->count.end();
	 ++n)
      std::cout << n->second << " times on line " << n->first << std::endl;
    ++w;
  }

  return 0;
}
