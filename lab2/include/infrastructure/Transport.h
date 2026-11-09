#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <string>

class Transport {
private:
    std::string transportId;
    std::string transportType;
    std::string route;
    int capacity;
    double fare;

public:
    Transport(
        const std::string& id,
        const std::string& type,
        const std::string& route,
        int capacity,
        double fare
    );

    void updateFare(double newFare);
    bool hasAvailableSeats(int passengers) const;
};

#endif