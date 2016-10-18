// calculate the squares of int values up to 100
// write the result in two columns

#include <cmath>
#include <iomanip>
#include <iostream>
// #include <vector>

// return the number of digits of an integer
// e.g. length(5648) returns 4
int length(const int& x)
{
  return static_cast<int>(std::log10(x) + 1);
}

int main()
{
  int FROM_NUM = 0;
  int TO_NUM = 1000;

  for (int i = FROM_NUM; i <= TO_NUM; ++i)
    {
      std::cout << std::setw(length(TO_NUM))
		<< i
		<< std::setw(length(TO_NUM * TO_NUM) + 1)
		<< i*i
		<< std::endl;
    }
  return 0;
}
