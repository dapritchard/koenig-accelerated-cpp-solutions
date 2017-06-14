#include "student_info.h"


// begin container_student definition
#ifndef CHAP05_STUDENT_CONTAINER_H_
#define CHAP05_STUDENT_CONTAINER_H_

// use compiler directive to choose a list.  Otherwise defaults to a vector
#ifndef LIST_CONTAINER_

#include <vector>
typedef std::vector<Student_info> student_container;
#define STUDENT_CONTAINER_SORT(ds, cmp) (sort((ds).begin(), (ds).end(), (cmp)))

#else

#include <list>
typedef std::list<Student_info> student_container;
#define STUDENT_CONTAINER_SORT(ds, cmp) ((ds).sort((cmp)))

#endif  // LIST_CONTAINER_


#endif  // CHAP05_STUDENT_CONTAINER_H_
