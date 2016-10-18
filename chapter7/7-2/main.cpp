/*
  modify the program in $4.2.3 to assign letter grades by ranges
*/

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <iterator>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>
#include "Student_info.h"
#include "grade.h"
#include "median.h"
#include "number_to_letter.h"

int main()
{
  std::map<std::string, int> grades;
  std::vector<Student_info> students;
  Student_info record;
  std::string::size_type maxlen = 0;

  // read and store all the records, and find the length of the longest name
  while (read(std::cin, record)) {
    maxlen = std::max(maxlen, record.name.size());
    students.push_back(record);
  }

  // alphabetize the records
  std::sort(students.begin(), students.end(), compare);

  for (std::vector<Student_info>::size_type i = 0;
       i != students.size(); ++i) {

    // write the name, padded on the right to maxlen + 1 characters
    std::cout << students[i].name
	 << std::string(maxlen + 1 - students[i].name.size(), ' ');

    try {
      double final_grade = grade(students[i]);
      std::string final_grade_letter = number_to_letter(final_grade);
      std::cout << final_grade_letter;

      // implement a map here!
      ++grades[final_grade_letter];

    } catch (std::domain_error e) {
      std::cout << e.what();
    }
    std::cout << std::endl;
  }

  std::map<std::string, int>::const_iterator it = grades.begin();
  while(it != grades.end()) {
    std::cout << it->second << " student(s) got "
	      << it->first << std::endl;
    ++it;
  }

  return 0;
}
