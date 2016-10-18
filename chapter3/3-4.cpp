// report the longest and the shortest string that has been input

#include <iostream>
#include <string>

int main()
{
  typedef std::string::size_type string_sz;

  std::cout << "Insert words, terminate with EOF: ";

  std::string shortest;
  std::string longest;
  std::string s;
  string_sz shortest_sz;
  string_sz longest_sz;
  string_sz s_sz;


  while (std::cin >> s)
    {
      s_sz = s.length();

      // the initial input is the shortest and the longest word
      if (shortest.length() == 0 && longest.length() == 0)
	{
	  shortest = s;
	  longest = s;
	  shortest_sz = s_sz;
	  longest_sz = s_sz;
	}

      if (s_sz < shortest_sz)
	{
	  shortest = s;
	  shortest_sz = s_sz;
	}
      if (s_sz > longest_sz)
	{
	  longest = s;
	  longest_sz = s_sz;
	}
    }

  std::cout << std::endl;
  std::cout << "longest word: " << longest << ", "
	    << longest_sz << " character(s)" << std::endl;
  std::cout << "shortest word: " << shortest << ", "
	    << shortest_sz << " character(s)" << std::endl;

  return 0;
}
