/*
  The framing program
  different separation for
*/

#include <iostream>
#include <string>

// say what standard library names we use
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
  // ask for the person's name
  cout << "Please enter your first name: ";

  // read the name
  string name;
  cin >> name;

  // build the message that we intend to write
  const string greeting = "Hello, " + name + "!";

  // ask for the number of blanks to leave at the top and the bottom
  cout << "How many spaces to leave at the top and the bottom? ";
  int pad_vert;
  cin >> pad_vert;
  cout << "How many spaces to leave at the sides? ";
  int pad_horiz;
  cin >> pad_horiz;

  // the number of columns to write
  const int rows = pad_vert * 2 + 3;
  const string::size_type cols = greeting.size() + pad_horiz * 2 + 2;

  // write a blank line to separate the output from the input
  cout << endl;

  // write rows of output
  // invariant: we have written r rows so far
  for (int r = 0; r != rows; ++r)
    {
      string::size_type c = 0;

      // is it time to write the greeting
      if (r == pad_vert + 1)
	{
	  string spaces(pad_horiz, ' ');
	  cout << '*' + spaces + greeting + spaces + '*';
	}
      else
	{
	  // are we on the first or last row?
	  if (r == 0 || r == rows-1)
	    {
	      string asterisks(cols, '*');
	      cout << asterisks;
	    }
	  else
	    {
	      string spaces(cols - 2, ' ');
	      cout << '*' + spaces + '*';
	    }
	}
      cout << endl;
    }

  return 0;
}
