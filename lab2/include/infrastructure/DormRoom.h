
#ifndef DORMROOM_H
#define DORMROOM_H

#include <string>

class Dormitory;


class DormRoom
{
private:
    std::string roomId;
    std::string dormitoryId;
    int roomNumber;
    int capacity;

    Dormitory* dormitory = nullptr;
public:
    DormRoom(
        const std::string& id,
        const std::string& dormId,
        int number,
        int roomCapacity
    );

    std::string getRoomId() const;
    std::string getDormitoryId() const;
    int getRoomNumber() const;
    int getCapacity() const;

    bool isFull(int currentResidents) const;
    void updateCapacity(int newCapacity);
};

#endif
