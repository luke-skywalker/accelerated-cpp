// given a vector of int, returns a map saying how many times every element occurrs

#include <iterator>
#include <map>
#include <vector>

std::map<int, int> count_map(const std::vector<int>& ints)
{
  // ret[line_number] = number of times
  std::map<int, int> ret;

  std::vector<int>::const_iterator cit;
  for (cit = ints.begin(); cit != ints.end(); ++cit)
    ++ret[*cit];

  return ret;
}
