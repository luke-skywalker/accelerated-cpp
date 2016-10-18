#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "compare.h"
#include "hcat.h"
#include "permutate_vector.h"
#include "permutation.h"
#include "split.h"

int main()
{
  std::string original = "the quick brown fox jumps over the lazy dog";

  // 0. split string at whitespace, make vector of strings
  std::vector<std::string> v;
  v = split(original);

  // 1. generate the permutations
  std::vector<permutation> perms;
  permutate_vector(v, perms);

  // 2. sort the vectors
  std::sort(perms.begin(), perms.end(), compare);

  // 3. build both sides of the sorted array
  std::vector<std::string> left, right;
  std::string tmp_left, tmp_right;
  for (std::vector<permutation>::size_type i = 0; i < perms.size(); ++i) {
    tmp_left.clear();
    tmp_right.clear();
    for (std::vector<std::string>::size_type j = 0; j < perms[i].key; ++j)
      tmp_left += v[j] + ' ';
    left.push_back(tmp_left);
    for (std::vector<std::string>::size_type j = perms[i].key; j < v.size(); ++j)
      tmp_right += v[j] + ' ';
    right.push_back(tmp_right);
  }

  // 4. formatting and printing the output
  std::vector<std::string> out = hcat(left, right);
  for (std::vector<std::string>::size_type i = 0; i < out.size(); ++i) {
    std::cout << out[i] << std::endl;
  }

  return 0;
}
