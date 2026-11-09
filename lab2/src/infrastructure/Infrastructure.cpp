#include "infrastructure/Infrastructure.h"

#include <stdexcept>

Infrastructure::Infrastructure(
    const std::string& infrastructureId,
    const std::string& infrastructureName,
    const std::string& location)
    : infrastructureId(infrastructureId),
      infrastructureName(infrastructureName),
      location(location),
      totalBuildings(0),
      totalRooms(0)
{
    if (infrastructureId.empty() ||
        infrastructureName.empty() ||
        location.empty())
    {
        throw std::invalid_argument(
            "Invalid infrastructure information"
        );
    }
}

std::string Infrastructure::getInfrastructureId() const
{
    return infrastructureId;
}

std::string Infrastructure::getInfrastructureName() const
{
    return infrastructureName;
}

std::string Infrastructure::getLocation() const
{
    return location;
}

int Infrastructure::getTotalBuildings() const
{
    return totalBuildings;
}

int Infrastructure::getTotalRooms() const
{
    return totalRooms;
}

void Infrastructure::addBuilding()
{
    ++totalBuildings;
}

void Infrastructure::removeBuilding()
{
    if (totalBuildings <= 0)
    {
        throw std::logic_error(
            "No buildings available to remove"
        );
    }

    --totalBuildings;
}

void Infrastructure::addRoom()
{
    ++totalRooms;
}

void Infrastructure::removeRoom()
{
    if (totalRooms <= 0)
    {
        throw std::logic_error(
            "No rooms available to remove"
        );
    }

    --totalRooms;
}

void Infrastructure::updateLocation(
    const std::string& newLocation)
{
    if (newLocation.empty())
    {
        throw std::invalid_argument(
            "Location cannot be empty"
        );
    }

    location = newLocation;
}