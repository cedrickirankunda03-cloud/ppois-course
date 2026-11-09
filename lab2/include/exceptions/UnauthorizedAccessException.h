#ifndef UNAUTHORIZED_ACCESS_EXCEPTION_H
#define UNAUTHORIZED_ACCESS_EXCEPTION_H

#include "DeaneryException.h"

class UnauthorizedAccessException : public DeaneryException {
public:
    using DeaneryException::DeaneryException;
};

#endif