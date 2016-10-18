// count how many times each word appears in the input
// things I learned from this:
//
// 1. if you're putting numbers in a stream, call them x
//                      strings                        s
// 2. a for loop will not be evaluated at all if the
//    condition is always false (Luca, you idiot)
// 3. put the tipedef at the beginning

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
  typedef std::vector<std::string>::size_type vec_sz;

  std::cout << "Input some words, terminate with EOF: ";

  std::vector<std::string> words;
  std::vector<int> count;
  std::string s;

  while (std::cin >> s)
    {
      // assume every word is unknown
      bool known_word = false;

      // compare it against the known words
      // if we find it in our "dictionary", then it is not unknown anymore
      for (vec_sz i = 0; i < words.size(); i++)
	{
	  if (s == words[i])
	    {
	      count[i]++;
	      known_word = true;
	    }
	}

      // if it is still unknown, add it to the "dictionary"
      if (!known_word)
	{
	  words.push_back(s);
	  count.push_back(1);
	}
    }

  // print the outcomes
  for (vec_sz i = 0; i < words.size(); i++)
    {
      std::cout << '"' << words[i] << '"' << " has been inserted "
  		<< count[i] << " times" << std::endl;
    }

  return 0;
}
