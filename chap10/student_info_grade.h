#ifndef CHAP10_STUDENT_INFO_GRADE_H_
#define CHAP10_STUDENT_INFO_GRADE_H_

#include <string>
#include <vector>

class StudentInfoGrade {
    
public:
    
    StudentInfoGrade();              // construct an empty `StudentInfoGrade' object
    StudentInfoGrade(std::istream&); // construct one by reading a stream
    
    std::istream& read(std::istream&);
    std::string name() const { return nm; }
    double grade() const;
    bool pass_status() const { return grade() >= 60.0; }
    std::string letter_grade() const;

    
private:
    
    std::string nm;
    double midterm, final, overall;
    std::vector<double> homework;
};

bool compare(const StudentInfoGrade&, const StudentInfoGrade&);

#endif
