// Page 186
//
// Rewrite the student-grading program from section 9.6 page 166 to generate
// letter grades.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "student_info_grade.h"

using std::cin;                    using std::cout;
using std::sort;                   using std::vector;
using std::string;                 using std::max;


int main()
{
    vector<StudentInfoGrade> students;
    StudentInfoGrade record;
    string::size_type maxlen = 0;

    // read and store the data
    while (record.read(cin)) {
	maxlen = max(maxlen, record.name().size());
	students.push_back(record);
    }

    // alphabetize the student records
    sort(students.begin(), students.end(), compare);

    // write the names and grades
    for (vector<StudentInfoGrade>::size_type i = 0; i != students.size(); ++i) {
	cout << students[i].name()
	     << string(maxlen + 2 - students[i].name().size(), ' ')
	     << students[i].letter_grade() + "\n";
    }
    
    return 0;
}
