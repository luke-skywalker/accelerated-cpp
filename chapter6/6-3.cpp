#include <vector>

int main()
{
  std::vector<int> u(10,100);
  std::vector<int> v;
  copy(u.begin(), u.end(), v.begin());

  return 0;
}
