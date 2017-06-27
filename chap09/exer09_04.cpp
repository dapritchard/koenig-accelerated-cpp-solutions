#include <iostream>
#include <sstream>
#include "student_info.h"

using std::cout;
using std::istringstream;


int main() {
    
    Student_info student;
    istringstream input("jim 80 76");
    
    student.read(input);
    if (student.valid()) {
    	cout << "student grade: " << student.grade() << "\n";
    } else {
    	cout << "the student grade input was invalid\n";
    }

    return 0;
}
