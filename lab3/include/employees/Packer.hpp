#pragma once
#include "Employee.hpp"
namespace wms {
class Packer : public Employee {
public:
    Packer(std::string id, std::string name) : Employee(std::move(id), std::move(name), Role::Packer) {}
    void packItem() {}
};
}
