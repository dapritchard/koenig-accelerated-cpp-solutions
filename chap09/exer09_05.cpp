#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "pf_student_info.h"

using std::cin;                    using std::cout;
using std::sort;                   using std::vector;
using std::string;                 using std::max;


int main()
{
    vector<PfStudentInfo> students;
    PfStudentInfo record;
    string::size_type maxlen = 0;

    // read and store the data
    while (record.read(cin)) {
	maxlen = max(maxlen, record.name().size());
	students.push_back(record);
    }

    // alphabetize the student records
    sort(students.begin(), students.end(), compare);

    // write the names and grades
    for (vector<PfStudentInfo>::size_type i = 0; i != students.size(); ++i) {
	cout << students[i].name()
	     << string(maxlen + 2 - students[i].name().size(), ' ')
	     << (students[i].pass_status() ? "P\n" : "F\n");
    }
    
    return 0;
}
