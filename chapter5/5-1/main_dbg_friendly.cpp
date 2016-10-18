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

  std::cout << "PERMUTATIONS" << std::endl;
  for (std::vector<permutation>::size_type j = 0; j < perms.size(); ++j) {
    std::cout << perms[j].key << ". ";
    for (std::vector<std::string>::size_type i = 0; i < perms[0].words.size(); ++i) {
      std::cout << perms[j].words[i] << ' ';
    }
    std::cout << std::endl;
  }

  // 2. sort the vectors
  std::sort(perms.begin(), perms.end(), compare);

  std::cout << "SORTING" <<std::endl;
  for (std::vector<permutation>::size_type j = 0; j < perms.size(); ++j) {
    std::cout << perms[j].key << ". ";
    for (std::vector<std::string>::size_type i = 0; i < perms[0].words.size(); ++i) {
      std::cout << perms[j].words[i] << ' ';
    }
    std::cout << std::endl;
  }

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

  std::cout << "SLICING -- LEFT SIDE" <<std::endl;
  for (std::vector<std::string>::size_type i = 0; i < left.size(); ++i)
    std::cout << left[i] << std::endl;
  std::cout << "SLICING -- RIGHT SIDE" <<std::endl;
  for (std::vector<std::string>::size_type i = 0; i < right.size(); ++i)
    std::cout << right[i] << std::endl;

  // 4. formatting and printing the output
  std::cout << "FINAL RESULT" <<std::endl;
  std::vector<std::string> out = hcat(left, right);
  for (std::vector<std::string>::size_type i = 0; i < out.size(); ++i) {
    std::cout << out[i] << std::endl;
  }

  return 0;
}
