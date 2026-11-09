
#ifndef ROOM_CAPACITY_EXCEEDED_EXCEPTION_H
#define ROOM_CAPACITY_EXCEEDED_EXCEPTION_H

#include "DeaneryException.h"

class RoomCapacityExceededException : public DeaneryException {
public:
    using DeaneryException::DeaneryException;
};

#endif
