#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"

int main()
{
  std::vector<Student_info> students;
  Student_info record;
  std::string::size_type maxlen = 0; // the length of the longest name

  // read and store all the students data.
  // Invariant: students contains all the student records read so far
  //   maxlen contains the length of the longest name in students
  while (read(std::cin, record))
    {
      //find length of longest name
      maxlen = std::max(maxlen, record.name.size());
      students.push_back(record);
    }

  // alphabetize the student records
  std::sort(students.begin(), students.end(), compare);

  // write the names and grades
  for (std::vector<Student_info>::size_type i = 0; i != students.size(); ++i)
    {
      // write the name, padded on the right to maxlen + 1 character
      std::cout << students[i].name
		<< std::string(maxlen + 1 - students[i].name.size(), ' ');
      // compute and write the grade
	  double final_grade = students[i].final_grade;
	  std::streamsize prec = std::cout.precision();
	  std::cout << std::setprecision(3) << final_grade
		    << std::setprecision(prec);
      std::cout << std::endl;
    }

  return 0;
}
