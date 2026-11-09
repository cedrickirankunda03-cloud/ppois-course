#include "administration/Building.h"
#include "administration/Room.h"

#include <stdexcept>

Building::Building(
    int buildingId,
    const std::string& name,
    const std::string& address
)
    : buildingId(buildingId),
      name(name),
      address(address)
{
    if (buildingId <= 0 || name.empty() || address.empty()) {
        throw std::invalid_argument("Invalid building information");
    }
}

std::string Building::getName() const {
    return name;
}

void Building::addRoom(Room* room) {
    if (room == nullptr) {
        throw std::invalid_argument("Room cannot be null");
    }

    rooms.push_back(room);
}

int Building::getRoomCount() const {
    return static_cast<int>(rooms.size());
}