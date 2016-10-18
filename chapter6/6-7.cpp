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

// returns a vector of students who did not do all homework, leaving
// those who did it in the original container
std::vector<Student_info> extract_didnt(std::vector<Student_info>& students)
{
  std::vector<Student_info>::iterator
    iter = stable_partition(students.begin(), students.end(), did_all_homework);
  std::vector<Student_info> didnt(iter, students.end());
  students.erase(iter, students.end());
  return didnt;
}

int main()
{
  std::vector<Student_info> all_students;
  Student_info student;

  // read all the records
  while (read(std::cin, student))
    all_students.push_back(student);

  // who didn't do the homework?
  std::vector<Student_info> didnt = extract_didnt(all_students);

  std::cout << std::endl << "THESE GUYS DID ALL THE HOMEWORK" << std::endl;
  display_students_name(all_students);

  std::cout << std::endl << "THESE GUYS DIDN'T DO ALL THE HOMEWORK" << std::endl;
  display_students_name(didnt);

  return 0;
}
