#include "infrastructure/Route.h"

#include <stdexcept>
#include <cmath>

Route::Route(
    const std::string& id,
    const std::string& start,
    const std::string& end,
    double distance,
    int duration
)
    : routeId(id),
      startLocation(start),
      endLocation(end),
      distance(distance),
      estimatedDuration(duration)
{
    if (id.empty() ||
        start.empty() ||
        end.empty() ||
        !std::isfinite(distance) ||
        distance < 0 ||
        duration <= 0)
    {
        throw std::invalid_argument(
            "Invalid route information"
        );
    }
}

void Route::updateDuration(int duration)
{
    if (duration <= 0)
    {
        throw std::invalid_argument(
            "Duration must be positive"
        );
    }

    estimatedDuration = duration;
}

double Route::getAverageSpeed() const
{
    return distance / (estimatedDuration / 60.0);
}