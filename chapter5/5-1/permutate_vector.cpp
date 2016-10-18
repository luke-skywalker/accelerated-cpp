// generate the permutations of a vector, store them in a structure of vectors
#include <string>
#include <vector>
#include "permutation.h"

int permutate_vector(std::vector<std::string>& v, std::vector<permutation>& p) {
  std::vector<std::string>::size_type v_length = v.size();

  // invariant: we have computed i permutations
  for (std::vector<std::string>::size_type i = 0; i != v.size(); ++i) {

    // push back new permutation created with default constructor
    p.push_back(permutation());

    // invariant: we have written j elements of the i-th permutation
    for (std::vector<std::string>::size_type j = 0; j != v.size(); ++j) {
      p[i].permutation_rule.push_back((i+j) % v_length);
      p[i].words.push_back(v[(i+j) % v_length]);
    }
    p[i].key = p[i].permutation_rule[0];
  }

  return 0;
}
