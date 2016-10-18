#ifndef GUARD_permutation
#define GUARD_permutation

struct permutation {
  // a vector of strings
  std::vector<std::string> words;
  // a vector of integers -- more exactly, a vector of size_type numbers
  std::vector<std::vector<std::string>::size_type> permutation_rule;
  // a single number, holding the key of the dictionary
  std::vector<std::string>::size_type key;
};

#endif
