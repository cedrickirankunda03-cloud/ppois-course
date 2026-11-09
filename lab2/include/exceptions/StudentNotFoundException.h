#ifndef STUDENT_NOT_FOUND_EXCEPTION_H
#define STUDENT_NOT_FOUND_EXCEPTION_H

#include "DeaneryException.h"
#include <string>

class StudentNotFoundException : public DeaneryException {
public:
    explicit StudentNotFoundException(const std::string& studentId);
};

#endif