#pragma once
#include "Employee.hpp"
namespace wms {
class SecurityGuard : public Employee {
public:
    SecurityGuard(std::string id, std::string name) : Employee(std::move(id), std::move(name), Role::Security) {}
    void patrol() {}
};
}
