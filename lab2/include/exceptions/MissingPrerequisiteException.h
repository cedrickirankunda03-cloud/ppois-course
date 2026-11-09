#ifndef MISSING_PREREQUISITE_EXCEPTION_H
#define MISSING_PREREQUISITE_EXCEPTION_H

#include "DeaneryException.h"

class MissingPrerequisiteException : public DeaneryException {
public:
    using DeaneryException::DeaneryException;
};

#endif