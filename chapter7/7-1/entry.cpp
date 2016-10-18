#include <list>
#include <numeric>
#include <string>
#include <vector>
#include "count_map.h"
#include "entry.h"

std::list<entry> map_to_structs(const std::map<std::string, std::vector<int> >& m)
{
  std::list<entry> entries;
  entry e;

  // invariant: we have copied it words
  std::map<std::string, std::vector<int> >::const_iterator it = m.begin();
  while (it != m.end()) {
    // save the word
    e.word = it->first;
    // save the number of occurrences per line
    e.count = count_map(it->second);
    // save the total number of occurrences
    std::map<int, int>::const_iterator cit = e.count.begin();
    e.tot_count = 0;
    while (cit != e.count.end()) {
      e.tot_count += cit->second;
      ++cit;
    }
    entries.push_back(e);
    ++it;
  }

  return entries;
}

bool occurrence_sort(const entry& x, const entry& y)
{
  return x.tot_count > y.tot_count;
}
