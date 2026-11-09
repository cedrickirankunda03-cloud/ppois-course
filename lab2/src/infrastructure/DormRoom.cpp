
#include "infrastructure/DormRoom.h"

#include <stdexcept>

DormRoom::DormRoom(
    const std::string& id,
    const std::string& dormId,
    int number,
    int roomCapacity
)
    : roomId(id),
      dormitoryId(dormId),
      roomNumber(number),
      capacity(roomCapacity)
{
    if (roomId.empty())
    {
        throw std::invalid_argument(
            "Room ID cannot be empty."
        );
    }

    if (dormitoryId.empty())
    {
        throw std::invalid_argument(
            "Dormitory ID cannot be empty."
        );
    }

    if (roomNumber <= 0)
    {
        throw std::invalid_argument(
            "Room number must be positive."
        );
    }

    if (capacity <= 0)
    {
        throw std::invalid_argument(
            "Room capacity must be positive."
        );
    }
}

std::string DormRoom::getRoomId() const
{
    return roomId;
}

std::string DormRoom::getDormitoryId() const
{
    return dormitoryId;
}

int DormRoom::getRoomNumber() const
{
    return roomNumber;
}

int DormRoom::getCapacity() const
{
    return capacity;
}

bool DormRoom::isFull(int currentResidents) const
{
    if (currentResidents < 0)
    {
        throw std::invalid_argument(
            "Resident count cannot be negative."
        );
    }

    return currentResidents >= capacity;
}

void DormRoom::updateCapacity(int newCapacity)
{
    if (newCapacity <= 0)
    {
        throw std::invalid_argument(
            "Room capacity must be positive."
        );
    }

    capacity = newCapacity;
}
