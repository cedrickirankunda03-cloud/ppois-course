#ifndef TEACHER_NOT_FOUND_EXCEPTION_H
#define TEACHER_NOT_FOUND_EXCEPTION_H

#include "DeaneryException.h"

class TeacherNotFoundException : public DeaneryException {
public:
    using DeaneryException::DeaneryException;
};

#endif