#pragma once

#include <string>
#include <vector>

class Infrastructure
{
private:
    std::string infrastructureId;
    std::string infrastructureName;
    std::string location;
    int totalBuildings;
    int totalRooms;

public:
    Infrastructure(const std::string& infrastructureId,
                   const std::string& infrastructureName,
                   const std::string& location);

    std::string getInfrastructureId() const;
    std::string getInfrastructureName() const;
    std::string getLocation() const;
    int getTotalBuildings() const;
    int getTotalRooms() const;

    void addBuilding();
    void removeBuilding();
    void addRoom();
    void removeRoom();
    void updateLocation(const std::string& newLocation);
};