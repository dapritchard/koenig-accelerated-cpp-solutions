/* Page 49
 *
 * The average-grade computation in Secion 3.1 (pages 35-36) might divide by
 * zero if the student didn't enter any grades.  Division by zero is undefined
 * in C++, which means that the implementation is permitted to do anything it
 * likes. What does your C++ implementation do in this case?  Rewrite the
 * program so that its behavior does not depend on how the implementation treats
 * division by zero.
 */

/* On my platform, performing 1 / 0 crashes the program with the message
 * `Floating point exception (core dumped)'.  Performing 1.0 / 0.0 results in a
 * value of infinity.
 */

#include <iomanip>
#ifndef __GNUC__
#include <ios>
#endif
#include <iostream>
#include <string>

using std::cin;                  using std::setprecision;
using std::cout;                 using std::string;
using std::endl;                 using std::streamsize;

int main()
{
	// ask for and read the student's name
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	// ask for and read the midterm and final grades
	cout << "Please enter your midterm and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;

	// ask for the homework grades
	cout << "Enter all your homework grades, "
	        "followed by end-of-file: ";

	// the number and sum of grades read so far
	int count = 0;
	double sum = 0;

	// a variable into which to read
	double x;

	// invariant:
	//     we have read `count' grades so far, and
	//     `sum' is the sum of the first `count' grades
	while (cin >> x) {
		++count;
		sum += x;
	}
	double hw_grade = (count == 0) ? 0.0 : sum / count;

	// write the result
	streamsize prec = cout.precision();
	cout << "Your final grade is " << setprecision(3)
	     << 0.2 * midterm + 0.4 * final + 0.4 * hw_grade
	     << setprecision(prec) << endl;

	return 0;
}
