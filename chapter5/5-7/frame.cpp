// draw a frame around a bunch of strings contained in a std::vector<std::string>

#include <string>
#include <vector>
#include "width.h"

std::vector<std::string> frame(const std::vector<std::string>& v)
{
  std::vector<std::string> ret;
  std::string::size_type maxlen = width(v);
  std::string border(maxlen + 4, '*');

  // write the top border
  ret.push_back(border);

  // write each interior row, bordered by an asterisk and a space
  for (std::vector<std::string>::size_type i = 0; i != v.size(); ++i)
    ret.push_back( "* "
		   + v[i]
		   + std::string(maxlen - v[i].size(), ' ')
		   + " *");

  // write the bottom border
  ret.push_back(border);
  return ret;
}
