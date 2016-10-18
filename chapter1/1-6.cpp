/*
  is >> s

  Reads and discards characters from the stream denoted by is until
  encountering a character that is not whitespace. Then reads
  successive characters from is into string, overwriting whatever
  value s might have had, until the next character read would be
  whitespace.
*/

#include <iostream>
#include <string>

int main()
{
  std::cout << "What is your name? ";
  std::string name;
  std::cin >> name;
  std::cout << "Hello, " << name << std::endl << "And what is yours? ";
  std::cin >> name;
  std::cout << "Hello, " << name << "; nice to meet you too!" << std::endl;
  return 0;
}
