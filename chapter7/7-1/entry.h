#ifndef GUARD_entry_h
#define GUARD_entry_h

#include <list>
#include <map>
#include <string>

struct entry
{
  std::string word;
  std::map<int, int> count; // <line, number of occurrences per line>
  int tot_count;
};

std::list<entry> map_to_structs(const std::map<std::string, std::vector<int> >&);
bool occurrence_sort(const entry&, const entry&);

#endif
