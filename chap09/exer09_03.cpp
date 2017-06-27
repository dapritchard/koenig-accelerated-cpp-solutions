#include <iostream>
#include <sstream>
#include <stdexcept>
#include "student_info.h"

using std::cout;
using std::istringstream;
using std::domain_error;


int main() {
    
    Student_info student;
    istringstream input("jim 80 76");

    student.read(input);
    try{
    	cout << "student grade: " << student.grade() << "\n";
    } catch (const domain_error& e) {
    	cout << "the try/catch block caught an error: " << e.what()<< "\n";
    }

    return 0;
}
