// see it in action in 6-0-3.cpp

double optimistic_median_analysis(const std::vector<Student_info>& students)
{
  std::vector<double> grades;

  std::transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);
  return median(grades);
}
