// Page 112
//
// The portion of the grading analysis program from section 6.2.1 page 110 that
// read and classified student records depending on whether they did (or did
// not) do all the homework is similar to the problem we solved in
// extract_fails.  Write a function to handle this subproblem.

#include <vector>
#include <iostream>
#include "analy_refactor.h"
#include "student_info.h"
#include "extract_didnt.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;


int main() {
    
    // students who did and didn't do all their homework
    vector<Student_info> did, didnt;

    // read all of the student records into `did'.  Later the students who
    // didn't do all of the homework will be removed
    Student_info student;
    while (read(cin, student)) {
	did.push_back(student);
    }

    // remove `Student_info's from `did' for students who didn't do all of the
    // homework and copy them to a vector which is returned from the function
    didnt = extract_didnt(did);

    // verify that the analyses will show us something
    if (did.empty()) {
	cout << "No student did all the homework!" << endl;
	return 1;
    }
    if (didnt.empty()) {
	cout << "Every student did all the homework!" << endl;
	return 1;
    }


    // do the analyses
    write_analysis(cout, "median", grade_aux, did, didnt);
    write_analysis(cout, "average", average_grade, did, didnt);
    write_analysis(cout, "median of homework turned in", optimistic_median, did, didnt);

    return 0;
}

