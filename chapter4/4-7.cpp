#include <iostream>
#include <stdexcept>
#include <vector>

double average(const std::vector<double>& cv) {
  typedef std::vector<double>::size_type vec_sz;
  double sum = 0;

  if (cv.empty())
    throw std::domain_error("average of an empty vector");

  for (vec_sz i = 0; i < cv.size(); ++i) {
    sum = sum + cv[i];
  }

  return sum / cv.size();
}

int main() {
  std::cout << "Numbers, please: ";

  std::vector<double> v;
  double x;
  while (std::cin >> x) {
    v.push_back(x);
  }

  std::cout << "The average is "
	    << average(v) << std::endl;
}
