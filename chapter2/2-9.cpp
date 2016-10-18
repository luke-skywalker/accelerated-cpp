// compare two numbers, tells which one is the largest

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  // ask for two integers
  cout << "Enter two integers separated by a space: ";

  // read the two numbers
  int num1;
  int num2;
  cin >> num1;
  cin >> num2;

  // is the first number bigger than the second?
  if (num1 > num2)
    cout << num1 << " is bigger than " << num2 << endl;
  // are the two numbers equal?
  else if (num1 == num2)
    cout << "The two numbers are equal" << endl;
  else
    cout << num2 << " is bigger than " << num1 << endl;

  return 0;
}
