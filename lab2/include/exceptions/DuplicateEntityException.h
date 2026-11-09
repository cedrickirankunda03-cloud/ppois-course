
#ifndef DUPLICATE_ENTITY_EXCEPTION_H
#define DUPLICATE_ENTITY_EXCEPTION_H

#include "DeaneryException.h"

class DuplicateEntityException : public DeaneryException {
public:
    using DeaneryException::DeaneryException;
};

#endif
