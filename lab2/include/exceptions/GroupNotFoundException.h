
#ifndef GROUP_NOT_FOUND_EXCEPTION_H
#define GROUP_NOT_FOUND_EXCEPTION_H

#include "DeaneryException.h"

class GroupNotFoundException : public DeaneryException {
public:
    using DeaneryException::DeaneryException;
};

#endif
