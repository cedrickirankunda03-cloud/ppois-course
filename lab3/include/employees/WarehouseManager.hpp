#pragma once
#include "Employee.hpp"
namespace wms {
class WarehouseManager : public Employee {
public:
    WarehouseManager(std::string id, std::string name) : Employee(std::move(id), std::move(name), Role::Manager) {}
    void approveOrder() {}
};
}
