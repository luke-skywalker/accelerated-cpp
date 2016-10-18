#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

struct Student_info {
  std::string name;
  double midterm, final;
  std::vector<double> homework;
};

// comparison function used for alphabetical sorting of the students
bool compare (const Student_info& s1, const Student_info& s2)
{
  return s1.name < s2.name;
}

// read the homework grades only from an input stream and store them in a vector
std::istream& read_hw(std::istream& in, std::vector <double>& hw)
{
  // is there a valid input stream?
  if (in) {
    // get rid of previous content, avoid reading crap from memory
    hw.clear();

    // read homework grades from the input stream
    double x;
    while (in >> x)
      hw.push_back(x);

    // reset the error status of the stream, in case there is any
    in.clear();
  }
  return in;
}

// read and store the student's name and grades from the input stream
std::istream& read(std::istream& is, Student_info& s)
{
  // read the midterm and final grades
  is >> s.name >> s.midterm >> s.final;

  // read the homework grades
  read_hw(is, s.homework);

  return is;
}

// compute and return the median of a vector, no side effects
double median(std::vector<double> vec)
{
  typedef std::vector<double>::size_type vec_sz;

  vec_sz size = vec.size();
  if (size == 0)
    throw std::domain_error("median of an empty vector");

  sort(vec.begin(), vec.end());

  vec_sz mid = size / 2;

  return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

// compute the final grade of a student, no side effects
// friendly name: GRADE1
double grade(double midterm, double final, double homework)
{
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// given all the student grades, returns three doubles:
// the midterm, the final and the homework.
// has no side effects
// friendly name: GRADE2
double grade(double midterm, double final, const std::vector<double>& hw)
{
  if (hw.size() == 0)
    throw std::domain_error("student has done no homework");
  // this is a call to GRADE1
  return grade(midterm, final, median(hw));
}

// write the midterm, final and homework grades in the appropriate place
// in the student's record
// friendly name: GRADE3
double grade(const Student_info& s)
{
  // this is a call to GRADE2
  return grade(s.midterm, s.final, s.homework);
}

int main()
{
  // read and store all the students data
  std::vector<Student_info> students;	// a vector of structures
  Student_info record;			// a single entry in the record, i.e. a structure
  std::string::size_type maxlen = 0;	// length of the longest name

  // invariant: students contains all the student records read so far
  while (read(std::cin, record)) {
    // find length of longest name
    maxlen = std::max(maxlen, record.name.size());
    // add the freshly read data to the students vector
    students.push_back(record);
  }

  // alphabetize the students record
  std::sort(students.begin(), students.end(), compare);

  // write the names and grades
  for (std::vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
    // write the name, padded on the right to maxlen + 1 character
    std::cout << students[i].name
	      << std::string(maxlen + 1 - students[i].name.size(), ' ');
    // compute and write the grade
    try {
      // this is a call to GRADE3
      double final_grade = grade(students[i]);
      std::streamsize prec = std::cout.precision();
      std::cout << std::setprecision(3) << final_grade
		<< std::setprecision(prec);
    }
    catch (std::domain_error e) {
      std::cout << e.what();
    }
    std::cout << std::endl;
  }
  return 0;
}
