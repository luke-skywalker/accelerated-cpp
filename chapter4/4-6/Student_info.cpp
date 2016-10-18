// source file for Student_info-related functions
#include <stdexcept>
#include "Student_info.h"
#include "grade.h" // because now we call the grade function!


bool compare(const Student_info& x, const Student_info& y)
{
  return x.name < y.name;
}

std::istream& read(std::istream& is, Student_info& s)
{
  // read and store the student's name and midterm and final exam grades
  double midterm;
  double final;
  is >> s.name >> midterm >> final;

  // read and store all the student's homework grades
  std::vector<double> homework;
  read_hw(is, homework);

  // compute the final grade of the student
  try
    {
      s.final_grade = grade(midterm, final, homework);
    }
  catch (std::domain_error e)
    {
      s.final_grade = -1; // submitted no homework
    }


  return is;
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
