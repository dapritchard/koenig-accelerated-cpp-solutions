#ifndef GUARD_Student_info
#define GUARD_Student_info

// `Student_info.h' header file
#include <iostream>
#include <string>
#include <vector>

struct Student_info {
    std::string name;
    double grade;
};

struct Student_grades {
    std::string name;
    double midterm;
    double final;
    std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_grades&);
std::istream& read_hw(std::istream&, std::vector<double>&);
#endif

