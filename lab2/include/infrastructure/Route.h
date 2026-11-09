#ifndef ROUTE_H
#define ROUTE_H

#include <string>

class Route {
private:
    std::string routeId;
    std::string startLocation;
    std::string endLocation;
    double distance;
    int estimatedDuration;

public:
    Route(
        const std::string& id,
        const std::string& start,
        const std::string& end,
        double distance,
        int duration
    );

    void updateDuration(int duration);
    double getAverageSpeed() const;
};

#endif