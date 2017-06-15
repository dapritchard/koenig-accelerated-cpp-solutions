#include <vector>
#include "student_info.h"
#include "grade.h"

using std::vector;


// modifies `students' so that the vector only contains `Student_info's for
// students who passed, and returns a vector with `Student_info's for students
// who failed.  The elements for both vectors remain the in same order as they
// were passed into the function.

vector<Student_info> extract_fails(vector<Student_info>& students) {
    
    vector<Student_info> fail;
    vector<Student_info>::const_iterator students_curr;
    vector<Student_info>::const_iterator students_end;
    vector<Student_info>::iterator students_pass;

    students_curr = students_pass = students.begin();
    students_end = students.end();

    // each iteration tests to see whether the student pointed to by
    // `students_curr' passed or failed the course.  If the student passed, his
    // / her `Student_info' is copied to the element in `students' one past the
    // last student who passed.  If the student failed, his / her `Student_info'
    // is appended to `fail'.
    for ( ; students_curr != students_end; students_curr++) {

	// case: student failed.  Append `Student_info' to `fail'.
	if (fgrade(*students_curr)) {
	    fail.push_back(*students_curr);
	}
	// case: student passed.  Copy `Student_info' to the first element of
	// `students' that we haven't yet copied a record to.
	else {
	    // case: not necessarily the same `Student_info'.  The test prevents
	    // unnecessary copying if we haven't yet seen a failing student.
	    if (students_pass != students_curr) {
		*students_pass = *students_curr;
	    }
	    // update `students_pass' so that we know where to place the next
	    // `Students_info'
	    students_pass++;
	}
    }

    // change the size of the container to only contain the students who passed
    // the course, i.e the students who's `Student_info's were copied to the beginning
    // of the vector
    students.resize(students_pass - students.begin());
    
    return fail;
}
