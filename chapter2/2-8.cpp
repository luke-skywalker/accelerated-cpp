// print the product of the numbers in the range [1,10)

#include <iostream>

int main()
{
  int i = 1;
  int product = 1;
  while (i < 10)
    {
      product = product * i;
      i++;
    }

  std::cout << product << std::endl;

  return 0;
}
