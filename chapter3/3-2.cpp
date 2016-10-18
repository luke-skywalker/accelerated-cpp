// compute the quartiles of a set of integers
// The quartiles are the points dividing a data-set in four equal parts.

#include <algorithm>	// used for the sort algorithm
#include <ios>		// defines the type streamsize
#include <iomanip>	// contains the manipulators, like setprecision
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::streamsize;
using std::vector;

int main()
{
  // ask for and read the set of integers
  cout << "Please enter the ingegers: " << endl;
  vector<double> v;
  int user_input;
  while (cin >> user_input)
    v.push_back(user_input);

  // check that the set of integers is non-empty
  typedef vector<double>::size_type vec_sz;
  vec_sz v_length = v.size();
  if (v_length == 0)
    {
      cout << "No numbers have been inserted! Exiting." << endl;

      return 1;
    }

  // sort the vector
  sort(v.begin(),v.end());

  // compute the median of the vector
  vec_sz mid = v_length / 2;
  double median = v_length % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];

  // split the vector in two halves
  vector<double> h1;
  vector<double> h2;

  for (vec_sz i = 0; i < mid; i++)
    h1.push_back(v[i]);

  if (v_length % 2 == 0)
    {
      for (vec_sz i = mid; i < v_length; i++)
	h2.push_back(v[i]);
    }
  else
    {
      for (vec_sz i = mid+1; i < v_length; i++)
	h2.push_back(v[i]);
    }

  // compute the first quartile as the median of the first half
  vec_sz h1_len = h1.size();
  vec_sz h1_mid = h1_len / 2;
  double h1_median = h1_len % 2 == 0 ? (h1[h1_mid] + h1[h1_mid - 1]) / 2 : h1[h1_mid];

  // compute the third quartile as the median of the third half
  vec_sz h2_len = h2.size();
  vec_sz h2_mid = h2_len / 2;
  double h2_median = h2_len % 2 == 0 ? (h2[h2_mid] + h2[h2_mid - 1]) / 2 : h2[h2_mid];

  // print the result
  streamsize prec = cout.precision();
  cout << setprecision(3)
       << "1st quartile: " << h1_median << endl
       << "2nd quartile: " << median << endl
       << "3rd quartile: " << h2_median << endl
       << setprecision(prec);

  return 0;
}
