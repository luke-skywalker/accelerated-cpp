/*
  Write '*' so that they form a square, a rectangle, a triangle
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
  // ask the user which figure he wants to draw
  cout << "What would you like to draw?" << endl;
  cout << "(1) a square" << endl;
  cout << "(2) a rectangle" << endl;
  cout << "(3) a triangle" << endl;

  // read the choice
  int shape;
  cin >> shape;

  // what are we drawing?
  if (shape == 1)
    // we draw a square
    {
      // ask the length of the side of the square
      cout << "Insert the length of the side of the square: ";
      int side;
      cin >> side;

      // leave a blank line
      cout << endl;

      for (int r = 0; r != side; ++r)
	{
	  // are we on the first or the last row?
	  if (r == 0 || r == side - 1)
	    {
	      string asterisks (side, '*');
	      cout << asterisks << endl;
	    }
	  else
	    {
	      string spaces (side - 2, ' ');
	      cout << '*' + spaces + '*' << endl;
	    }
	}
    }
  else if (shape == 2)
    // we draw a rectangle
    {
      // ask the length of the sides of the rectangle
      cout << "Insert width and height of the rectangle, separated by a space: ";
      int width;
      int height;
      cin >> width;
      cin >> height;

      // leave a blank line
      cout << endl;

      for (int r = 0; r != height; ++r)
	{
	  // are we on the first or the last row?
	  if (r == 0 || r == height - 1)
	    {
	      string asterisks (width, '*');
	      cout << asterisks << endl;
	    }
	  else
	    {
	      string spaces (width - 2, ' ');
	      cout << '*' + spaces + '*' << endl;
	    }
	}

    }
  else if (shape == 3)
    // we draw a triangle
    {
      // ask the length of the side of the triangle
      cout << "Insert the length of the catetus of the triangle: ";
      int side;
      cin >> side;

      // leave a blank line
      cout << endl;

      // invariant: we have written r rows so far
      for (int r = 0; r != side; ++r)
	{
	  // are we on the  first row?
	  if (r == 0)
	    {
	      cout << '*' << endl;
	    }
	  // are we on the last row?
	  else if (r == side -1)
	    {
	      string asterisks (side, '*');
	      cout << asterisks << endl;
	    }
	  else
	    {
	      string spaces (r - 1, ' ');
	      cout << '*' + spaces + '*' << endl;
	    }
	}
    }

  return 0;
}
