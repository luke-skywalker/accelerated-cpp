#include <string>
#include <vector>
#include "width.h"

std::vector<std::string> hcat(const std::vector<std::string>& left,
			      const std::vector<std::string>& right)
{
  std::vector<std::string> ret;

  // add 1 to leave a space between pictures
  std::string::size_type width1 = width(left) + 1;

  // indices to look at elements from left and tight respectively
  std::vector<std::string>::size_type i = 0, j = 0;

  // continue until we've seen all rows from both pictures
  while (i != left.size() || j != right.size()) {
    // construct new string to hold characters from both pictures
    std::string s;

    // copy a row from the left-hand side, if there is one
    if (i != left.size())
      s = left[i++];

    // pad to full width
    s += std::string(width1 - s.size(), ' ');

    // copy a row from the right-hand side, if there is one
    if (j != right.size())
      s += right[j++];

    // add s to the picture we're creating
    ret.push_back(s);
  }
  return ret;
}
