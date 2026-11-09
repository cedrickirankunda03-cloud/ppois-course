
#ifndef SCHEDULE_CONFLICT_EXCEPTION_H
#define SCHEDULE_CONFLICT_EXCEPTION_H

#include "DeaneryException.h"

class ScheduleConflictException : public DeaneryException {
public:
    using DeaneryException::DeaneryException;
};

#endif
