#pragma once

#include <string>

class InfrastructureBuilding {
private:
    std::string buildingId;
    std::string buildingName;
    std::string addressId;
    int numberOfFloors;

public:
    InfrastructureBuilding(
        const std::string& buildingId,
        const std::string& buildingName,
        const std::string& addressId,
       int numberOfFloors
    );

    std::string getBuildingId() const;
    std::string getBuildingName() const;
     std::string getAddressId() const;

    void updateBuildingName(const std::string& name);
    void updateNumberOfFloors(int floors);
};