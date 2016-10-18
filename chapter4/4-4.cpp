// calculate the squares of int values up to 100
// write the result in two columns
// TIL: casting happens automatically!

#include <cmath>
#include <iomanip>
#include <iostream>
// #include <vector>

// return the number of digits of an integer
// e.g. length(5648) returns 4
int length(const double& x)
{
  // return static_cast<int>(std::log10(x) + 1);
  return std::log10(x) + 1;
}

int main()
{
  double FROM_NUM = 0;
  double TO_NUM = 1000;

  for (double i = FROM_NUM; i <= TO_NUM; ++i)
    {
      std::cout << std::setw(length(TO_NUM))
		<< i
		<< std::setw(length(TO_NUM * TO_NUM) + 1)
		<< i*i
		<< std::endl;
    }
  return 0;
}
