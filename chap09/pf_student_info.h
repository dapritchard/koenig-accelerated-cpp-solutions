#ifndef CHAP09_PF_STUDENT_INFO_H_
#define CHAP09_PF_STUDENT_INFO_H_

#include <string>
#include <vector>

class PfStudentInfo {
    
 public:
    
    PfStudentInfo();              // construct an empty `PfStudentInfo' object
    PfStudentInfo(std::istream&); // construct one by reading a stream
    
    std::string name() const { return nm; }
    std::istream& read(std::istream&);
    double grade() const;
    bool pass_status() const { return grade() >= 60.0; }

    
 private:
    
    std::string nm;
    double midterm, final, overall;
};

bool compare(const PfStudentInfo&, const PfStudentInfo&);

#endif
