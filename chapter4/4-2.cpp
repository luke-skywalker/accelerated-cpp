// calculate the squares of int values up to 100
// write the result in two columns

#include <iomanip>
#include <iostream>
int main()
{
  for (int i = 0; i <= 100; ++i)
      std::cout << std::setw(3) << i
		<< std::setw(6) << i*i << std::endl;

  return 0;
}
