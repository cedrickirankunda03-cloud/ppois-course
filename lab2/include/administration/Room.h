
#ifndef ROOM_H
#define ROOM_H

#include <string>

class Building;
class Schedule;

class Room {
private:
    int roomNumber;
    int capacity;
    Building* building;
    Schedule* schedule;

public:
    // Constructor
    Room(
        int roomNumber,
        int capacity,
        Building* building,
        Schedule* schedule
    );

    // Get room number
    int getRoomNumber() const;

    // Get capacity
    int getCapacity() const;

    // Check available capacity
    bool hasCapacity(int students) const;
};

#endif
