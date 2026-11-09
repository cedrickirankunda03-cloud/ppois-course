#pragma once

#include <string>

class Address;


class Dormitory
{
private:
    std::string dormitoryId;
    std::string dormitoryName;
    std::string address;
    int totalRooms;

    Address* addressRef = nullptr;
public:
    Dormitory(const std::string& dormitoryId,
              const std::string& dormitoryName,
              const std::string& address,
              int totalRooms);

    std::string getDormitoryId() const;
    std::string getDormitoryName() const;
    int getTotalRooms() const;

    void updateAddress(const std::string& address);
    void updateTotalRooms(int rooms);
    bool hasAvailableRooms() const;
};
