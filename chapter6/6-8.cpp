#include <algorithm>
#include <iostream>
#include <numeric>
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

std::istream& read(std::istream& is, Student_info& s)
{
  // read and store the student's name and midterm and final exam grades
  is >> s.name >> s.midterm >> s.final;

  read_hw(is, s.homework); // read and store all the student's homework grades
  return is;
}

// check if the student's name has an even number of letters
bool has_a_nice_name(const Student_info& s)
{
  return s.name.size() % 2 == 0;
}

// returns a vector of students with names whose number of letters is odd
// only students with an even number of letters are left in "all_students"
std::vector<Student_info> extract_ugly_names(std::vector<Student_info>& students)
{
  std::vector<Student_info>::iterator
    iter = stable_partition(students.begin(), students.end(), has_a_nice_name);
  std::vector<Student_info> not_nice(iter, students.end());
  students.erase(iter, students.end());
  return not_nice;
}

int main()
{
  std::vector<Student_info> all_students;
  Student_info student;

  // read all the records
  while (read(std::cin, student))
    all_students.push_back(student);

  // who didn't do the homework?
  std::vector<Student_info> not_nice = extract_ugly_names(all_students);

  std::cout << std::endl << "THESE GUYS HAVE A NICE NAME, THEY PASS" << std::endl;
  display_students_name(all_students);

  std::cout << std::endl << "THESE GUYS HAVE AN UGLY NAME, THEY FAIL" << std::endl;
  display_students_name(not_nice);

  return 0;
}
