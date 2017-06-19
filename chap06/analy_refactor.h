#ifndef CHAP06_ANALY_REFACTOR_H_
#define CHAP06_ANALY_REFACTOR_H_

#include <string>
#include <vector>
#include "student_info.h"

bool did_all_hw(const Student_info& s);
double grade_aux(const Student_info& s);
double average_grade(const Student_info& s);
double optimistic_median(const Student_info& s);
void write_analysis(std::ostream& out, const std::string& name,
                    double grade_scheme(const Student_info&),
                    const std::vector<Student_info>& did,
                    const std::vector<Student_info>& didnt);
double analysis(const std::vector<Student_info>& students,
		double grade_scheme(const Student_info&));

#endif
