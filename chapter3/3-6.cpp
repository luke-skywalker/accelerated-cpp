// same as 3-5, handling the division by 0 in case there are 0 home assignments.
// By default gcc would return a NaN

#include <iomanip>	// support for setprecision()
#include <ios>		// support for the streamsize type
#include <iostream>
#include <string>
#include <vector>

int main()
{
  typedef std::vector<std::string>::size_type vec_sz;

  std::string name;
  std::vector<std::string> names;
  std::vector<double> midterm;
  std::vector<double> final;
  std::vector<double> homework;

  std::cout << "How many home assignments? ";
  int home_assignment_no = 0;
  std::cin >> home_assignment_no;


  // we are not done as long as there are students
  bool done = false;

  while (!done)
    {
      name.clear();
      std::cout << "Insert the student name: ";
      std::cin >> name;
      if (name.empty())
	{
	  std::cout << "No name inserted, quitting." << std::endl;
	  return 1;
	}

      names.push_back(name);

      std::cout << "Insert " << name << "'s midterm and final grades: ";
      double mid_grade, final_grade;
      std::cin >> mid_grade >> final_grade;
      midterm.push_back(mid_grade);
      final.push_back(final_grade);

      // what to do if there are 0 home assignments?
      if (home_assignment_no == 0)
	{
	  homework.push_back(0);
	}
      else
	{
	  std::cout << "Insert " << name << "'s homework grades: ";
	  int count = 0;
	  double sum = 0;
	  double x = 0;
	  // invariant: we have read and summed "count" grades
	  while (count < home_assignment_no)
	    {
	      std::cin >> x;
	      ++count;
	      sum += x;
	    }
	  double avg_homework_grade = sum / count;
	  homework.push_back(avg_homework_grade);
	}

      std::cout << "Done? [y/n]: ";
      std::string ans;
      std::cin >> ans;
      if (ans == "y")
	done = true;
      std::cout << std::endl;
    }

  std::streamsize prec = std::cout.precision();
  for (vec_sz i = 0; i < names.size(); i++)
    {
      std::cout << "---" << names[i] << "'s grades ---" << std::endl
		<< std::setprecision(3)
		<< "Midterm: " << midterm[i] << std::endl
		<< "Final exam: " << final[i] << std::endl
		<< "Homework: " << homework[i] << std::endl
		<< "FINAL GRADE: "
		<< 0.4 * midterm[i] + 0.4 * final[i] + 0.2 * homework[i]
		<< std::setprecision(prec)
		<< std::endl;
      std::cout << std::endl;
    }

  return 0;
}
