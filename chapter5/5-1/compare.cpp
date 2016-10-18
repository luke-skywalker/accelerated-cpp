#include <algorithm>
#include <string>
#include <vector>
#include "permutation.h"

bool compare(const permutation& p1, const permutation& p2)
{
  std::string x = p1.words[0];
  std::string y = p2.words[0];

  std::vector<std::string> original, sorted;
  original.push_back(x);
  original.push_back(y);

  sorted = original;
  std::sort(sorted.begin(), sorted.end());

  // was it already sorted?
  if (original[0] == sorted[0])
    return true;
  else
    return false;
}
