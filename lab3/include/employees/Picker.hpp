#pragma once
#include "Employee.hpp"
namespace wms {
class Picker : public Employee {
    int itemsPicked_;
public:
    Picker(std::string id, std::string name) : Employee(std::move(id), std::move(name), Role::Picker), itemsPicked_(0) {}
    void recordPick() { ++itemsPicked_; }
    int itemsPicked() const noexcept { return itemsPicked_; }
};
}
