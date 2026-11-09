
#include "infrastructure/Cafeteria.h"

#include <stdexcept>

Cafeteria::Cafeteria(
    const std::string& id,
    const std::string& name,
    const std::string& location,
    int capacity
)
    : cafeteriaId(id),
      cafeteriaName(name),
      location(location),
      seatingCapacity(capacity)
{
    if (id.empty() ||
        name.empty() ||
        location.empty() ||
        capacity <= 0)
    {
        throw std::invalid_argument(
            "Invalid cafeteria information"
        );
    }
}

std::string Cafeteria::getCafeteriaId() const
{
    return cafeteriaId;
}

std::string Cafeteria::getCafeteriaName() const
{
    return cafeteriaName;
}

std::string Cafeteria::getLocation() const
{
    return location;
}

int Cafeteria::getSeatingCapacity() const
{
    return seatingCapacity;
}

void Cafeteria::updateSeatingCapacity(int capacity)
{
    if (capacity <= 0)
    {
        throw std::invalid_argument(
            "Seating capacity must be positive"
        );
    }

    seatingCapacity = capacity;
}

bool Cafeteria::hasAvailableSeats(int occupiedSeats) const
{
    if (occupiedSeats < 0)
    {
        throw std::invalid_argument(
            "Occupied seats cannot be negative"
        );
    }

    return occupiedSeats < seatingCapacity;
}
