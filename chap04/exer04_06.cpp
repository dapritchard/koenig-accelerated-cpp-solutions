/* Rewrite the Student_info structure to calculate the grades immediately and
 * store only the final grade.
 */

/* the program below is the revised grading program found in section 4.5 on
 * pages 70-71 with some small changes
 */

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "student_info.h"

using std::cin;                     using std::setprecision;
using std::cout;                    using std::sort;
using std::domain_error;            using std::streamsize;
using std::endl;                    using std::string;
using std::max;                     using std::vector;




int main()
{
    vector<Student_info> students;
    Student_grades record;
    string::size_type maxlen = 0;       // the length of the longest name

    // read and store all the students' data.
    // Invariant:	`students' contains all the student records read so far
    //			`maxlen' contains the length of the longest name in `students'
    while (read(cin, record)) {

	Student_info final_grade;

	// calculate final grade and store in `final_grade'
	try {
	    final_grade.name = record.name;
	    final_grade.grade = grade(record);
	}
	catch (domain_error e) {
	    cout << e.what();
	}
	
	// find length of longest name
	maxlen = max(maxlen, record.name.size());
	students.push_back(final_grade);
    }

    // alphabetize the student records
    sort(students.begin(), students.end(), compare);

    // write the names and grades
    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {

	// write the name, padded on the right to `maxlen' `+' `1' characters
	cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

	// write the grade
	streamsize prec = cout.precision();
	cout << setprecision(3) << students[i].grade << setprecision(prec) << endl;
    }
    return 0;
}
