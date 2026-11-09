
#ifndef CAFETERIA_H
#define CAFETERIA_H

#include <string>

class Cafeteria
{
private:
    std::string cafeteriaId;
    std::string cafeteriaName;
    std::string location;
    int seatingCapacity;

public:
    Cafeteria(
        const std::string& id,
        const std::string& name,
        const std::string& location,
        int capacity
    );

    std::string getCafeteriaId() const;
    std::string getCafeteriaName() const;
    std::string getLocation() const;
    int getSeatingCapacity() const;

    void updateSeatingCapacity(int capacity);

    bool hasAvailableSeats(int occupiedSeats) const;
};

#endif
