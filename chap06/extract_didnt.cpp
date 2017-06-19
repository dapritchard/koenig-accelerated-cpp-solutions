#include <vector>
#include "student_info.h"
#include "analy_refactor.h"

using std::vector;


// modifies `students' so that the vector only contains `Student_info's for
// students who did all of the homework, and returns a vector with
// `Student_info's for students who didn't do all of the homework.  The elements
// for both vectors remain in the same order as they were passed into the
// function.

vector<Student_info> extract_didnt(vector<Student_info>& students) {
    
    vector<Student_info> didnt;
    vector<Student_info>::const_iterator students_curr;
    vector<Student_info>::const_iterator students_end;
    vector<Student_info>::iterator students_did;

    students_curr = students_did = students.begin();
    students_end = students.end();

    // each iteration tests to see whether the student pointed to by
    // `students_curr' did all of the homework or not.  If the student did, his
    // / her `Student_info' is copied to the element in `students' one past the
    // last student who did.  If the student didn't, his / her `Student_info' is
    // appended to `didnt'.
    
    for ( ; students_curr != students_end; students_curr++) {

	// case: student didn't do all of the homework.  Append `Student_info'
	// to `didnt'.
	if (! did_all_hw(*students_curr)) {
	    didnt.push_back(*students_curr);
	}
	// case: student did all of the homework.  Copy `Student_info' to the
	// first element of `students' that we haven't yet copied a record to.
	else {
	    // case: not necessarily the same `Student_info'.  The test prevents
	    // unnecessary copying if we haven't yet seen a student who didn't
	    // do all of the homework.
	    if (students_did != students_curr) {
		*students_did = *students_curr;
	    }
	    // update `students_did' so that we know where to place the next
	    // `Students_info'
	    students_did++;
	}
    }

    // change the size of the container to only contain the students who did all
    // of the homework, i.e the students who's `Student_info's were copied to
    // the beginning of the vector
    
    students.resize(students_did - students.begin());
    
    return didnt;
}
