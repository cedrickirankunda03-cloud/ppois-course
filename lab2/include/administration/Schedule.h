
#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <vector>

class Room;

class Schedule {
private:
    int scheduleId;
    std::vector<Room*> rooms;

public:
    explicit Schedule(int scheduleId);

    int getScheduleId() const;

    void addRoom(Room* room);
    int getRoomCount() const;
};

#endif
