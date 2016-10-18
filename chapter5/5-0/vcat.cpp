#include <string>
#include <vector>

std::vector<std::string> vcat(const std::vector<std::string>& top,
			      const std::vector<std::string>& bottom)
{
  // copy the top picture
  std::vector<std::string> ret = top;

  // copy entire bottom picture
  ret.insert(ret.end(), bottom.begin(), bottom.end());
  // *** the line above does the same as this ***
  // for (std::vector<std::string>::const_interator it = bottom.begin();
  //      it != bottom.end(); ++it)
  //   ret.push_back(*it);

  return ret;
}
