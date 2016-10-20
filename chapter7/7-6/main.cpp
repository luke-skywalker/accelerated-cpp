// reimplementation of 7-0-2, without recursion

/*
  a Grammar is a description specifying how to create sentences;
            it is a map mapping a string to a Rule collection

	    <noun>        [ [ "cat" ],
	                    [ "dog" ],
			    [ "johnny" ],
			    [ "jb", "hankamanka", "junior" ] ]

	    <verb>        [ [jumps],
	                    [laughs],
			    [prays] ]

	    <location>    [ [ "on", "the", "table" ] ]

	    <sentence>    [ [the <noun> <verb> <location>],
	                    [the <noun> <verb>] ]
            __________    _______________________________________________________
	     ^             ^
	     string        Rule collection

  a Rule collection is a vector of Rules

  a Rule is a vector of strings;
         it can have only one string, like [ "cat" ]
	 or more than one string, like [ "on", "the", "table" ]
	                            or [ "jb", "hankamanka", "junior" ]

*/

#include <cstdlib>
#include <ctime>     // providing a seed for the prand number generator
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>
#include "split.h"

// these need to be shared amongs all programs
// I wonder how to cleanly deal with typedefs when one has multiple headers
typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammar;

// check if a word is bracketed
bool bracketed(const std::string& s)
{
  /*   operator precedence recap:
       1.  >
       2.  ==
       3.  &&
   */
  return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

// return a random integer in the range [0,n)
int nrand(int n)
{
  if (n <= 0 || n > RAND_MAX)
    throw std::domain_error("Argument to nrand is out of range");

  const int bucket_size = RAND_MAX / n;
  int r;

  do r = rand() / bucket_size;
  while (r >= n);

  return r;
}

void gen_aux(const Grammar& g,
	     const std::string& word,
	     std::vector<std::string>& ret)
{
  // This function is being modified not to use any recursive call.
  // Two vectors are used:
  // * one will hold the fully unwound, generated sentence
  // * the other will hold the rules and will be used as a stack.
  Rule rule_stack;

  // fetch the sentence (assumed one has been input correctly)
  Grammar::const_iterator it = g.find(word);
  if (it == g.end())
    throw std::logic_error("empty rule");
  const Rule_collection& c = it->second;
  // select (the/a) sentence
  const Rule& r = c[nrand(c.size())];

  // store it as a vector of string in ret
  for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
    ret.push_back(*i);

  // check for things that need to be expanded
  bool needToExpand = true;
  int pos; // position of the bracketed words

  while (needToExpand)
    {
      int check = 0;
      Rule::const_iterator i;
      for (i = ret.begin(); i != ret.end(); ++i)
	{
	  rule_stack.clear();
	  if (bracketed(*i))
	    {
	      // expand bracketed things in the stack
	      it = g.find(*i);
	      if (it == g.end())
		throw std::logic_error("empty rule");
	      rule_stack = it->second[nrand(c.size())];
	      // get out of the loop, remembering where we are
	      pos = i - ret.begin();
	      break;
	    }
	}

      ret.erase(ret.begin() + pos);
      ret.insert(ret.begin() + pos, rule_stack.begin(), rule_stack.end());

      for (i = ret.begin(); i != ret.end(); ++i)
	if (bracketed(*i))
	  check += 1;

      if (check == 0)
	needToExpand = false;
    }
}


// generate a sentence given a grammar
std::vector<std::string> gen_sentence(const Grammar& g)
{
  std::vector<std::string> ret;
  gen_aux(g, "<sentence>", ret);
  return ret;
}

// read a grammar from a given input stream
Grammar read_grammar(std::istream& in)
{
  Grammar ret;
  std::string line;

  // read the input
  while (getline(in, line)) {

    // split the input into words
    std::vector<std::string> entry = split(line);
    if (!entry.empty())
      // use the category to store the associated rule
      ret[entry[0]].push_back(
			      Rule( entry.begin() + 1, entry.end() )
			      );
  }
  return ret;
}

int main()
{
  // seed the pseudo-random number generator
  std::srand(std::time(0));

  // generate the sentence
  std::vector<std::string> sentence = gen_sentence(read_grammar(std::cin));

  // write the first word, if any
  std::vector<std::string>::const_iterator it = sentence.begin();
  if (!sentence.empty()) {
    std::cout << *it;
    ++it;
  }

  // write the rest of the words, each preceded by a space
  while (it != sentence.end()) {
    std::cout << " " << *it;
    ++it;
  }

  std::cout << std::endl;
  return 0;
}
