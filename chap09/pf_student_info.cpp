#include <iostream>
#include <vector>
#include "grade.h"
#include "pf_student_info.h"

using std::istream;


double PfStudentInfo::grade() const {
    return overall;
}


bool compare(const PfStudentInfo& x, const PfStudentInfo& y) {
    return x.name() < y.name();
}


PfStudentInfo::PfStudentInfo(): midterm(0), final(0), overall(0) { }


PfStudentInfo::PfStudentInfo(istream& is) {
    read(is);
}


istream& PfStudentInfo::read(istream& in) {
    in >> nm >> midterm >> final;
    overall = 0.5 * midterm + 0.5 * final;
    return in;
}
