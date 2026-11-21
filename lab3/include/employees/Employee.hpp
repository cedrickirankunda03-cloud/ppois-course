#pragma once
#include <string>
#include "Role.hpp"
namespace wms {
class Employee {
    std::string id_;
    std::string name_;
    Role role_;
public:
    Employee(std::string id, std::string name, Role role) : id_(std::move(id)), name_(std::move(name)), role_(role) {}
    const std::string& id() const noexcept { return id_; }
    Role role() const noexcept { return role_; }
};
}
