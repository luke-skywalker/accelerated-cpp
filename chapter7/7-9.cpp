/*

  output a random number in a range whose upper limit is higher than RAND_MAX

  The idea is to split our range [0, n) into RAND_MAX big buckets,
  choose a bucket using our regular rand() function, then keep doing
  this up to the point where big bucket size is less than rand(). At
  that point, we just have to choose a random number in that range
  using nrand()

*/

#include <cstdlib>	// RAND_MAX
#include <ctime>        // providing a seed for the prand number generator
#include <functional>   // modulus
#include <iomanip>	// setw
#include <iostream>	// cout, endl
#include <limits>       // numeric_limits
#include <stdexcept>    // domain_error
#include <string>

typedef unsigned long long int ullint;

// output a random integer in the range (0, n), n <= RAND_MAX
int nrand(int n)
{
  if (n <= 0 || n > RAND_MAX )
    throw std::domain_error("Argument to nrand is out of range");

  const int bucket_size = RAND_MAX / n;
  int r;

  do
    r = rand() / bucket_size;
  while (r >= n);

  return r;
}

int main()
{
  // seed the pseudo(!)-random number generator
  int seed = std::time(0);
  std::srand(seed);

  // the absolute maximum value we can have as an input
  ullint absmax = std::numeric_limits<ullint>::max();

  std::cout << "A random number will be generate in the range [0, n). Enter n: "
            << std::endl;

  // checking user input
  long double user_in;
  std::cin >> user_in;
  if (user_in < 0 || user_in > absmax )
    throw std::domain_error("Number should be smaller than "
                            + std::to_string(absmax) );

  // n stores the valid user input
  ullint n = (ullint)user_in;

  // variable containing the final randomly generated number
  ullint r = 0;

  // our first bucket is [0, n), that we want to split into RAND_MAX buckets
  ullint bucket_size = n;

  /*
    we then choose a bucket at random amongst the RAND_MAX buckets, and split
    this bucket into another RAND_MAX buckets.
    we keep doing so up to the point where bucket_size < RAND_MAX.

    a small graphical representation:

    0                                                                     n
    |---------------------------------------------------------------------|

    0
    |------|------|------|------|------|------|------|------|------|------|
       ^       ^     ^                                                ^
       |       |     |                                                |
    bucket0    |   bucket2 ...                                 bucketRAND_MAX
            bucket1

    say rand() returned 3, now we split bucket 3 into RAND_MAX buckets

    r = 3 * bucket_size
    |
    v
    |------|------|------|------|------|------|------|------|------|------|
       ^       ^     ^                                                ^
       |       |     |                                                |
    bucket3.0  |   bucket3.2 ...                              bucket3.RAND_MAX
            bucket3.1

    ...and so on, as needed

  */

  while (bucket_size > RAND_MAX)
    {
      bucket_size = bucket_size / RAND_MAX;
      r += rand() * bucket_size;
    }

  // at this point, we can just choose a number at random in the interval
  // [0, n%r)] using nrand();
  r += nrand(bucket_size);
  std::cout << "The random number generated is " << r << std::endl;
  std::cout << "Normalizing to (0,1), the number is "
            << (float)r / n << std::endl;

  return 0;
}
