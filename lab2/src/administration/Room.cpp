
#include "administration/Room.h"

#include <stdexcept>

Room::Room(
    int roomNumber,
    int capacity,
    Building* building,
    Schedule* schedule
) : roomNumber(roomNumber),
    capacity(capacity),
    building(building),
    schedule(schedule) {

    if (roomNumber <= 0 || capacity <= 0) {
        throw std::invalid_argument("Invalid room number or capacity");
    }

    if (building == nullptr || schedule == nullptr) {
        throw std::invalid_argument("Building and schedule cannot be null");
    }
}

int Room::getRoomNumber() const {
    return roomNumber;
}

int Room::getCapacity() const {
    return capacity;
}

bool Room::hasCapacity(int students) const {
    return students >= 0 && students <= capacity;
}
