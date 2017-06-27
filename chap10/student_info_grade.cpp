#include <iostream>
#include <vector>
#include <cstddef>
#include <string>
#include "grade.h"
#include "student_info_grade.h"

using std::istream;
using std::string;
using std::vector;


StudentInfoGrade::StudentInfoGrade(): midterm(0), final(0), overall(0) { }


StudentInfoGrade::StudentInfoGrade(istream& is) {
    read(is);
}


// read homework grades from an input stream into a `vector<double>'
istream& read_hw(istream& in, vector<double>& hw)
{
    if (in) {
	// get rid of previous contents
	hw.clear();

	// read homework grades
	double x;
	while (in >> x)
	    hw.push_back(x);

	// clear the stream so that input will work for the next student
	in.clear();
    }
    return in;
}


// read student grades and store in class members
istream& StudentInfoGrade::read(istream& in)
{        
    in >> nm >> midterm >> final;
    read_hw(in, homework);
    overall = ::grade(midterm, final, homework);

    return in;
}


// compute letter grade
string StudentInfoGrade::letter_grade() const {
    
    // range posts for numeric grades
    static const double numbers[] = {
	97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
    };

    // names for the letter grades
    static const char* const letters[] = {
	"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
    };

    // compute the number of grades given the size of the array
    // and the size of a single element
    static const size_t ngrades = sizeof(numbers) / sizeof(*numbers);

    // given a numeric grade, find and return the associated letter grade
    for (size_t i = 0; i < ngrades; ++i) {
	if (grade() >= numbers[i])
	    return letters[i];
    }

    return "?\?\?";
}


// overall grade getter
double StudentInfoGrade::grade() const {
    return overall;
}


// comparison of `StudentInfoGrade' lexographically by student name
bool compare(const StudentInfoGrade& x, const StudentInfoGrade& y) {
    return x.name() < y.name();
}
