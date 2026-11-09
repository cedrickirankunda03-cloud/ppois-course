
#ifndef SCHOLARSHIP_LIMIT_EXCEEDED_EXCEPTION_H
#define SCHOLARSHIP_LIMIT_EXCEEDED_EXCEPTION_H

#include "DeaneryException.h"

class ScholarshipLimitExceededException : public DeaneryException {
public:
    using DeaneryException::DeaneryException;
};

#endif
