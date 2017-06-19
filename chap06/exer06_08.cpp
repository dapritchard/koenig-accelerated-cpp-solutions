// Page 112
//
// Write a single function that can be used to classify students based on
// criteria of your choice.  Test this function by using it in place of the
// extract_fails program, and use it in the program to analyze student grades.

#include <vector>
#include <iostream>
#include "analy_refactor.h"
#include "student_info.h"
#include "extract_if.h"

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
    didnt = extract_if(did, did_all_hw);

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

