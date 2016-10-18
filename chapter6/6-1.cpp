// abusing of library algorithms and iterators

#include <algorithm>
#include <iostream>
#include <istream>
#include <iterator>
#include <string>
#include <vector>

/*
  ---------- WIDTH_CPP ----------

  This is the original function.

  std::string::size_type width(const std::vector<std::string>& v)
  {
    std::string::size_type maxlen = 0;
    for (std::vector<std::string>::size_type i = 0; i != v.size(); ++i)
      maxlen = std::max(maxlen, v[i].size());
    return maxlen;
  }

  This function operates on a contanier (a vector of strings), so the
  new approach os to write an auxiliary function operating on
  container elements (i.e. strings) and apply that to the whole
  container using iterators

  Length is the auxiliary function that computes the length of a
  string (it is just a wrapper for string.size()), and width is then
  rewritten using std::transform

*/

std::string::size_type length(const std::string& s)
{
  return s.size();
}

std::string::size_type width(const std::vector<std::string>& v)
{
  std::vector<std::string::size_type> v_sz;
  std::transform(v.begin(), v.end(), back_inserter(v_sz), length);

  // max_element returns an iterator, thus we need do dereference!
  return *(std::max_element(v_sz.begin(), v_sz.end()));
}

/*
  ---------- FRAME_CPP ----------

  This is the original function.

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

  I thought of rewriting this

  for (std::vector<std::string>::size_type i = 0; i != v.size(); ++i)
    ret.push_back( "* "
                 + v[i]
                 + std::string(maxlen - v[i].size(), ' ')
                 + " *");

  turning it into something like

  std::transform(v.begin(), v.end(), back_inserter(ret), decorate_string)

  but decorate_string would need to know maxlen and I don't know how
  to do that in a clean way neither I feel like using nested functions

*/

std::vector<std::string> frame(const std::vector<std::string>& v)
{
  std::vector<std::string> ret;
  std::string::size_type maxlen = width(v);
  std::string border(maxlen + 4, '*');
  std::vector<std::string>::const_iterator cit;

  // write the top border
  ret.push_back(border);

  // write each interior row, bordered by an asterisk and a space
  for (cit =v.begin(); cit != v.end(); ++cit)
    ret.push_back( "* "
  		   + *cit
  		   + std::string(maxlen - cit->size(), ' ')
  		   + " *");

  // write the bottom border
  ret.push_back(border);
  return ret;
}

/*
  ---------- HCAT_CPP ----------

  This is the original function.

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

*/

std::vector<std::string> hcat(const std::vector<std::string>& left,
			      const std::vector<std::string>& right)
{
  std::vector<std::string> ret;

  // add 1 to leave a space between pictures
  std::string::size_type width1 = width(left) + 1;

  // indices to look at elements from left and tight respectively
  std::vector<std::string>::const_iterator i = left.begin(), j = right.begin();

  // continue until we've seen all rows from both pictures
  while (i != left.end() || j != right.end()) {
    // construct new string to hold characters from both pictures
    std::string s;

    // copy a row from the left-hand side, if there is one
    if (i != left.end())
      s = *i++;

    // pad to full width
    s += std::string(width1 - s.size(), ' ');

    // copy a row from the right-hand side, if there is one
    if (j != right.end())
      s += *j++;

    // add s to the picture we're creating
    ret.push_back(s);
  }
  return ret;
}

std::istream& read_vector(std::istream& is, std::vector<std::string>& v)
{
  v.clear();
  std::string s;
  while (is >> s)
    v.push_back(s);
  is.clear();
  return is;
}


int main()
{
  std::vector<std::string> l, r;
  std::vector<std::string>::const_iterator cit;

  std::cout << "LEFT THINGS" << std::endl;
  read_vector(std::cin, l);

  std::cout << "RIGHT THINGS" << std::endl;
  read_vector(std::cin, r);

  std::vector<std::string> v = hcat(l, r);
  std::vector<std::string> v_framed = frame(v);

  for (cit = v_framed.begin(); cit != v_framed.end(); ++cit) {
    std::cout << *cit << std::endl;
  }

  return 0;
}
