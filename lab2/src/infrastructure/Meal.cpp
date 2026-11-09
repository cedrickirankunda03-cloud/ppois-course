#include "infrastructure/Meal.h"

#include <stdexcept>
#include <cmath>

Meal::Meal(
    const std::string& id,
    const std::string& name,
    const std::string& cafeteriaId,
    double price,
    const std::string& type
)
    : mealId(id),
      mealName(name),
      cafeteriaId(cafeteriaId),
      price(price),
      mealType(type)
{
    if (id.empty() ||
        name.empty() ||
        cafeteriaId.empty() ||
        type.empty() ||
        !std::isfinite(price) ||
        price < 0)
    {
        throw std::invalid_argument(
            "Invalid meal information"
        );
    }
}

void Meal::updatePrice(double newPrice)
{
    if (!std::isfinite(newPrice) || newPrice < 0)
    {
        throw std::invalid_argument(
            "Meal price cannot be negative or invalid"
        );
    }

    price = newPrice;
}

bool Meal::isAffordable(double budget) const
{
    if (!std::isfinite(budget) || budget < 0)
    {
        throw std::invalid_argument(
            "Budget cannot be negative or invalid"
        );
    }

    return budget >= price;
}