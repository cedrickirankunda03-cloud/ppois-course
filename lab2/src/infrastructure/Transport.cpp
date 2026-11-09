#include "infrastructure/Transport.h"

#include <stdexcept>
#include <cmath>

Transport::Transport(
    const std::string& id,
    const std::string& type,
    const std::string& route,
    int capacity,
    double fare
)
    : transportId(id),
      transportType(type),
      route(route),
      capacity(capacity),
      fare(fare)
{
    if (id.empty() ||
        type.empty() ||
        route.empty() ||
        capacity <= 0 ||
        !std::isfinite(fare) ||
        fare < 0)
    {
        throw std::invalid_argument("Invalid transport information");
    }
}

void Transport::updateFare(double newFare)
{
    if (!std::isfinite(newFare) || newFare < 0)
    {
        throw std::invalid_argument(
            "Transport fare cannot be negative or invalid"
        );
    }

    fare = newFare;
}

bool Transport::hasAvailableSeats(int passengers) const
{
    if (passengers < 0)
    {
        throw std::invalid_argument(
            "Passenger count cannot be negative"
        );
    }

    return passengers <= capacity;
}
