#ifndef ADMINISTRATION_BUILDING_H
#define ADMINISTRATION_BUILDING_H

#include <string>
#include <vector>

class Room;

class Building {
private:
    int buildingId;
    std::string name;
    std::string address;
    std::vector<Room*> rooms;

public:
    Building(int buildingId,
             const std::string& name,
             const std::string& address);

    std::string getName() const;
    void addRoom(Room* room);
    int getRoomCount() const;
};

#endif