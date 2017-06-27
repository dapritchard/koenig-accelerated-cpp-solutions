#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "pf_student_info.h"
#include "extract_vec_if.h"

using std::cin;                    using std::cout;
using std::sort;                   using std::vector;
using std::string;


bool my_pass_status(const PfStudentInfo& record) {
    return record.pass_status();
}


int main()
{
    vector<PfStudentInfo> students, pass;
    PfStudentInfo record;

    // read and store the data
    while (record.read(cin)) {
	students.push_back(record);
    }

    // remove passing students
    pass = extract_vec_if(students, my_pass_status);

    // alphabetize the student records
    sort(pass.begin(), pass.end(), compare);
    sort(students.begin(), students.end(), compare);

    // write the names and grades
    cout << "Passing students:\n"
	 << "-----------------\n";
    for (vector<PfStudentInfo>::size_type i = 0; i != pass.size(); ++i) {
	cout << pass[i].name() << "\n";
    }
    cout << "\n"
	 << "Failing students:\n"
	 << "-----------------\n";
    for (vector<PfStudentInfo>::size_type i = 0; i != students.size(); ++i) {
	cout << students[i].name() << "\n";
    }
    
    return 0;
}
