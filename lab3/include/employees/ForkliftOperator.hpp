#pragma once
#include "Employee.hpp"
namespace wms {
class ForkliftOperator : public Employee {
    std::string licenseId_;
public:
    ForkliftOperator(std::string id, std::string name, std::string licenseId) 
        : Employee(std::move(id), std::move(name), Role::ForkliftOperator), licenseId_(std::move(licenseId)) {}
};
}
