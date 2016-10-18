// implemented as per in $6.3.2 "A single-pass solution"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <stdexcept>
#include <string>
#include <vector>

struct Student_info
{
  std::string name;
  double midterm, final;
  std::vector<double> homework;
};

void display_students_name(std::vector<Student_info> s)
{
  std::vector<Student_info>::const_iterator cit;
  for (cit = s.begin(); cit != s.end(); ++cit)
    std::cout << cit->name << std::endl;
}

// read homework grades from an input stream into a 'vector'
std::istream& read_hw(std::istream& in, std::vector<double>& hw)
{
  if (in)
    {
      // get rid of previous contents
      hw.clear();

      // read homework grades
      double x;
      while (in >> x)
        hw.push_back(x);

      // clear the stream so that input will work for the next student
      in.clear();
    }
  return in;
}

double median(std::vector<double> vec)
{
  typedef std::vector<double>::size_type vec_sz;

  vec_sz size = vec.size();
  if (size == 0)
    throw std::domain_error("median of an empty vector");

  std::sort(vec.begin(), vec.end());

  vec_sz mid = size / 2;

  return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}

double average(const std::vector<double>& v)
{
  return std::accumulate(v.begin(), v.end(), 0.0) / v.size();
}

std::istream& read(std::istream& is, Student_info& s)
{
  // read and store the student's name and midterm and final exam grades
  is >> s.name >> s.midterm >> s.final;

  read_hw(is, s.homework); // read and store all the student's homework grades
  return is;
}

// check the last element of the "homework" vector
// if it is 0, it means that the student did not submit the last assignment
//
// this allows to (in a later function) separate the students into two
// groups: those who did all the home assignments, and those who did
// not
bool did_all_homework(const Student_info& s)
{
  return ((std::find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}

double grade(double midterm, double final, double homework)
{
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const std::vector<double>& hw)
{
  if (hw.size() == 0)
    throw std::domain_error("student has done no homework");
  // this is a call to GRADE1
  return grade(midterm, final, median(hw));
}

double grade(const Student_info& s)
{
  // this is a call to GRADE2
  return grade(s.midterm, s.final, s.homework);
}

double grade_aux(const Student_info& s)
{
  try {
    return grade(s);
  } catch (std::domain_error) {
    return grade(s.midterm, s.final, 0);
  }
}

// median of the nonzero elements of s.homework, or 0 if no such elements exist
double optimistic_median(const Student_info& s)
{
  std::vector<double> nonzero;
  remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);

  if (nonzero.empty())
    return grade(s.midterm, s.final, 0);
  else
    return grade(s.midterm, s.final, median(nonzero));
}

double average_grade(const Student_info & s)
{
  return grade(s.midterm, s.final, average(s.homework));
}

double average_analysis(const std::vector<Student_info>& students)
{
  std::vector<double> grades;

  std::transform(students.begin(), students.end(), back_inserter(grades), average_grade);
  return median(grades);
}

double median_analysis(const std::vector<Student_info>& students)
{
  std::vector<double> grades;

  std::transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
  return median(grades);
}

double optimistic_median_analysis(const std::vector<Student_info>& students)
{
  std::vector<double> grades;

  std::transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);
  return median(grades);
}

void write_analysis(std::ostream& out, const std::string& name,
		    double analysis(const std::vector<Student_info>&),
		    const std::vector<Student_info>& did,
		    const std::vector<Student_info>& didnt)
{
  out << name << ": median(did) = " << analysis(did)
      << ", median(didnt) = " << analysis(didnt) << std::endl;
}

bool fgrade(const Student_info& s)
{
  return grade(s) < 60;
}

bool pgrade(const Student_info& s)
{
  return !fgrade(s);
}

// returns a vector of students who failed, leaving those who passed in
std::vector<Student_info> extract_fails(std::vector<Student_info>& students)
{
  std::vector<Student_info>::iterator iter = stable_partition(students.begin(), students.end(), pgrade);
  std::vector<Student_info> fail(iter, students.end());
  students.erase(iter, students.end());
  return fail;
}

int main()
{
  std::vector<Student_info> did, didnt, all_students;
  Student_info student;

  // read all the records, separating them based on wheter all
  // homework was done
  while (read(std::cin, student)) {
    if (did_all_homework(student))
      did.push_back(student);
    else
      didnt.push_back(student);
    all_students.push_back(student);
  }

  // check that both groups contain data
  if (did.empty()) {
    std::cout << "No student did all the homework!" << std::endl;
    return 1;
  }
  if (didnt.empty()) {
    std::cout << "Every student did all the homework!" << std::endl;
    return 1;
  }

  // do the analyses
  write_analysis(std::cout, "median", median_analysis, did, didnt);
  write_analysis(std::cout, "average", average_analysis, did, didnt);
  write_analysis(std::cout, "median of homework turned in", optimistic_median_analysis, did, didnt);

  // a look at who passed and who failed
  std::vector<Student_info> fail = extract_fails(all_students);

  std::cout << std::endl << "THESE GUYS PASSED" << std::endl;
  display_students_name(all_students);

  std::cout << std::endl << "THESE GUYS FAILED" << std::endl;
  display_students_name(fail);


  return 0;
}
