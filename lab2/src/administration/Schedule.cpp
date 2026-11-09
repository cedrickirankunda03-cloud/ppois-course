
#include "administration/Schedule.h"
#include "administration/Room.h"

#include <stdexcept>

Schedule::Schedule(int scheduleId)
    : scheduleId(scheduleId)
{
    if (scheduleId <= 0) {
        throw std::invalid_argument("Schedule ID must be positive.");
    }
}

int Schedule::getScheduleId() const {
    return scheduleId;
}

void Schedule::addRoom(Room* room) {
    if (room == nullptr) {
        throw std::invalid_argument("Room cannot be null.");
    }

    rooms.push_back(room);
}

int Schedule::getRoomCount() const {
    return static_cast<int>(rooms.size());
}
