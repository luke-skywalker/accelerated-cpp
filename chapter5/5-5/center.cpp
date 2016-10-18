#include <string>
#include <vector>
#include "width.h"

std::vector<std::string> center(const std::vector<std::string>& v)
{
  // find the length of the longest string amongst those inserted
  std::string::size_type maxlen = width(v);

  std::vector<std::string> ret;
  std::string::size_type half_padding;
  for (std::vector<std::string>::size_type i = 0; i != v.size(); ++i) {
    half_padding = maxlen - v[i].size() / 2;
    ret.push_back(std::string(half_padding, ' ')
		  + v[i]
		  + std::string(half_padding, ' '));
  }
  return ret;
}
