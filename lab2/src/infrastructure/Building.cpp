
#include "infrastructure/Building.h"

#include <stdexcept>

InfrastructureBuilding::InfrastructureBuilding(
    const std::string& buildingId,
    const std::string& buildingName,
    const std::string& addressId,
    int numberOfFloors)
    : buildingId(buildingId),
      buildingName(buildingName),
      addressId(addressId),
      numberOfFloors(numberOfFloors)
{
    if (buildingId.empty() ||
        buildingName.empty() ||
        addressId.empty() ||
        numberOfFloors <= 0)
    {
        throw std::invalid_argument(
            "Invalid building information"
        );
    }
}

std::string InfrastructureBuilding::getBuildingId() const
{
    return buildingId;
}

std::string InfrastructureBuilding::getBuildingName() const
{
    return buildingName;
}

void InfrastructureBuilding::updateBuildingName(
    const std::string& name)
{
    if (name.empty())
    {
        throw std::invalid_argument(
            "Building name cannot be empty"
        );
    }

    buildingName = name;
}

std::string InfrastructureBuilding::getAddressId() const
{
    return addressId;
}

void InfrastructureBuilding::updateNumberOfFloors(int floors)
{
    if (floors <= 0)
    {
        throw std::invalid_argument(
            "Number of floors must be positive"
        );
    }

    numberOfFloors = floors;
}
