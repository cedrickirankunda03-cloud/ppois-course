#include "infrastructure/Dormitory.h"

#include <stdexcept>

Dormitory::Dormitory(
    const std::string& dormitoryId,
    const std::string& dormitoryName,
    const std::string& address,
    int totalRooms)
    : dormitoryId(dormitoryId),
      dormitoryName(dormitoryName),
      address(address),
      totalRooms(totalRooms)
{
    if (dormitoryId.empty() ||
        dormitoryName.empty() ||
        address.empty() ||
        totalRooms < 0)
    {
        throw std::invalid_argument(
            "Invalid dormitory information"
        );
    }
}

std::string Dormitory::getDormitoryId() const
{
    return dormitoryId;
}

std::string Dormitory::getDormitoryName() const
{
    return dormitoryName;
}

int Dormitory::getTotalRooms() const
{
    return totalRooms;
}

void Dormitory::updateAddress(const std::string& address)
{
    if (address.empty())
    {
        throw std::invalid_argument(
            "Address cannot be empty"
        );
    }

    this->address = address;
}

void Dormitory::updateTotalRooms(int rooms)
{
    if (rooms < 0)
    {
        throw std::invalid_argument(
            "Room count cannot be negative"
        );
    }

    totalRooms = rooms;
}

bool Dormitory::hasAvailableRooms() const
{
    return totalRooms > 0;
}