// By using a typedef, we can write one version of the program that implements
// either a vector-based solution or a list-based one.  Write and test this
// version of the program.

// The typedef `student_container' is defined in `student_container.h'.  Use the
// compiler directive defining `LIST_CONTAINER_' to specify the list-based
// version of the program, otherwise the vector-based version is used.
//
// Compiling the list-based versus the vector-based version requires linking
// against fails_list.o versus fails_vector.o.  See the makefile for all of the
// details.


#include <algorithm>
#include <iostream>
#include "student_container.h"
#include "grade.h"

student_container extract_fails(student_container& v);

//driver program for grade partitioning examples

using std::cin;
using std::cout;
using std::endl;
using std::sort;


int main() {
    
    student_container vs;
    Student_info s;

    // each iteration reads student grades one student at-a-time, and appends to
    // vs
    while (read(cin, s)) {
	vs.push_back(s);
    }

    // extract failing students and store in `fails'
    student_container fails = extract_fails(vs);

    // sort failing students container
    STUDENT_CONTAINER_SORT(fails, compare);

    // each iteration writes the name and grade for a failling student
    for (student_container::const_iterator curr = fails.begin();
    	 curr != fails.end(); curr++) {
	    
    	cout << curr->name << " " << grade(*curr) << endl;
    }

    return 0;
}
