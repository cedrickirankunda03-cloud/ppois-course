#ifndef MEAL_H
#define MEAL_H

#include <string>

class Cafeteria;


class Meal {
private:
    std::string mealId;
    std::string mealName;
    std::string cafeteriaId;
    double price;
    std::string mealType;

    Cafeteria* cafeteria = nullptr;
public:
    Meal(
        const std::string& id,
        const std::string& name,
        const std::string& cafeteriaId,
        double price,
        const std::string& type
    );

    void updatePrice(double newPrice);
    bool isAffordable(double budget) const;
};

#endif
