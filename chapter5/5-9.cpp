#include <cctype>
#include <string>
#include <iostream>

int main()
{
  std::string s;
  while (std::cin >> s) {
    // make the input uppercase
    std::string S(s.size(), ' ');
    for (std::string::size_type i = 0; i != s.size(); ++i)
      S[i] = toupper(s[i]);
    // printing the output
    for (std::string::size_type i = 0; i != s.size(); ++i)
      std::cout << S[i];

    std::cout << std::endl;
  }

  return 0;
}
