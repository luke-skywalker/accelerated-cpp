// #include <iomanip>
#include <iostream>
#include <string>
#include <vector>

/*
  Important things
  ----------------
  * streams can only be passed by reference
  * returning the reference to the stream is a way to indicate wheter the
    attempted input was succesful or not
  * calling clear() on a stream does not empty it! it resets its error state
*/
std::istream& read(std::istream& is, std::vector<std::string>& words)
{
  // is there any valid input to read?
  if (is){
    // get rid of previous content
    words.clear();

    // read words
    std::string w;
    while (is >> w)
      words.push_back(w);

    // reset the error state of the stream
    is.clear();
  }
  return is;
}

// experimenting with const and pass by reference
void print_vector(const std::vector<std::string>& cv)
{
  typedef std::vector<std::string>::size_type vec_sz;
  for (vec_sz i = 0; i < cv.size(); ++i){
    std::cout << cv[i] << std::endl;
  }
}

int main()
{
  typedef std::vector<std::string>::size_type vec_sz;

  // acquire words
  std::vector<std::string> words;
  read(std::cin, words);

  // print words
  std::cout << std::endl;
  std::cout << "Here are all the words you entered." << std::endl;
  print_vector(words);
  std::cout << std::endl;

  // find unique words
  std::vector<std::string> uniques;
  std::vector<int> count;

  for (vec_sz i = 0; i < words.size(); ++i){
    bool known = false;
    for (vec_sz j = 0; j < uniques.size(); ++j){
      if (words[i] == uniques[j]){
	++count[j];
	known = true;
      }
    }
    if (!known){
      uniques.push_back(words[i]);
      count.push_back(1);
    }
  }

  // output results
  std::cout << "You entered " << words.size()
	    << " words." << std::endl;
  std::cout << "You entered " << uniques.size()
	    << " unique words." << std::endl;
  std::cout << std::endl;
  for (vec_sz i = 0; i < uniques.size(); ++i){
    std::cout << uniques[i] << " has been entered "
	      << count[i] << " times." << std::endl;
  }

  return 0;
}
