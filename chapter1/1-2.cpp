/* This will not compile.
   The reason is that the overloading of the "+" operator is not defined
   for string literals. That is, the part that does not work is

   "Hello" + ", world"

   Since "+" is left associative, this could be made to work by changing
   that line in

   "Hello" + (", world" + xclam)

   In this case it would work since xclam is a string, and the overloading
   of "+" is defined in such a way that

   string literal + std::string

   returns an object which is a std::string
*/

#include <iostream>
#include <string>

int main()
{
  const std::string xclam = "!";
  const std::string message = "Hello" + ", world" + xclam;

  std::cout << xclam << std::endl;
  std::cout << message << std::endl;

  return 0;
}
