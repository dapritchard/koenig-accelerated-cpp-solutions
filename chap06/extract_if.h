#ifndef CHAP06_EXTRACT_IF_H_
#define CHAP06_EXTRACT_IF_H_

#include <vector>
#include "student_info.h"

std::vector<Student_info> extract_if(std::vector<Student_info>& students,
				     bool pred(const Student_info&));


#endif
