// reimplementation of 7-0-2, without recursion

/*
  a Grammar is a description specifying how to create sentences

  For example, "the <noun-phrase> <verb> <location>" is a grammar.

*/

#include <cstdlib>
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

// void gen_aux(const Grammar& g,
// 	     const std::string& word,
// 	     std::vector<std::string>& ret)
// {
//   // is the word not bracketed?
//   // if the word is not bracketed, it represents itself: so we can
//   // append it to ret and we're done
//   if (!bracketed(word)) {
//     ret.push_back(word);
//   } else {
//     // locate the rule that corresponds to word
//     // std::map.find() searches through the keys of the map
//     Grammar::const_iterator it = g.find(word);
//     // did we not have a rule related to that word?
//     if (it == g.end())
//       throw std::logic_error("empty rule");

//     // fetch the set of possible rules...
//     //
//     // that is if "it" is our iterator, then **for example**
//     //    it->first points to <name>
//     //    it->second points to Luca
//     const Rule_collection& c = it->second;

//     // ...from which we select one at random
//     const Rule& r = c[nrand(c.size())];

//     // recursively expand the selected rule
//     for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
//       gen_aux(g, *i, ret);
//   }
// }

void gen_aux(const Grammar& g,
	     const std::string& word,
	     std::vector<std::string>& ret)
{
  // is the word not bracketed?
  // if the word is not bracketed, it represents itself: so we can
  // append it to ret and we're done
  if (!bracketed(word)) {
    ret.push_back(word);
  } else {
    // locate the rule that corresponds to word
    // std::map.find() searches through the keys of the map
    Grammar::const_iterator it = g.find(word);
    // did we not have a rule related to that word?
    if (it == g.end())
      throw std::logic_error("empty rule");

    // fetch the set of possible rules...
    //
    // that is if "it" is our iterator, then **for example**
    //    it->first points to <name>
    //    it->second points to Luca
    const Rule_collection& c = it->second;

    // ...from which we select one at random
    const Rule& r = c[nrand(c.size())];

    // recursively expand the selected rule
    for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
      gen_aux(g, *i, ret);
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
      ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
  }
  return ret;
}

int main()
{
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
