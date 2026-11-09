
#ifndef GRADE_OUT_OF_BOUNDS_EXCEPTION_H
#define GRADE_OUT_OF_BOUNDS_EXCEPTION_H

#include "DeaneryException.h"

class GradeOutOfBoundsException : public DeaneryException {
public:
    using DeaneryException::DeaneryException;
};

#endif
