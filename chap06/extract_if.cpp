#include <vector>
#include "student_info.h"
#include "analy_refactor.h"

using std::vector;


// modifies `students' so that the vector only contains `Student_info's for
// students who satify `pred', and returns a vector with the remaining
// `Student_info's.  The elements for both vectors remain in the same order as
// they were passed into the function.

vector<Student_info> extract_if(vector<Student_info>& students,
				   bool pred(const Student_info&)) {
    
    vector<Student_info> remove;
    vector<Student_info>::const_iterator students_curr;
    vector<Student_info>::const_iterator students_end;
    vector<Student_info>::iterator students_keep;

    students_curr = students_keep = students.begin();
    students_end = students.end();

    // each iteration tests to see whether the student pointed to by
    // `students_curr' satisfied `pred'.  If the student did, his / her
    // `Student_info' is copied to the element in `students' one past the last
    // student who did.  If the student didn't, his / her `Student_info' is
    // appended to `remove'.
    
    for ( ; students_curr != students_end; students_curr++) {

	// case: student didn't satisfy `pred'.  Append `Student_info' to
	// `remove'.
	if (! pred(*students_curr)) {
	    remove.push_back(*students_curr);
	}
	// case: student satisfied `pred'.  Copy `Student_info' to the first
	// element of `students' that we haven't yet copied a record to.
	else {
	    // case: not necessarily the same `Student_info'.  The test prevents
	    // unnecessary copying if we haven't yet seen a student who didn't
	    // do all of the homework.
	    if (students_keep != students_curr) {
		*students_keep = *students_curr;
	    }
	    // update `students_keep' so that we know where to place the next
	    // `Students_info'
	    students_keep++;
	}
    }

    // change the size of the container to only contain the students that
    // satisfied `pred', i.e the students who's `Student_info's were copied to
    // the beginning of the vector
    
    students.resize(students_keep - students.begin());
    
    return remove;
}
