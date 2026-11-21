#pragma once
#include <string>
#include "../core/Address.hpp"
#include "../core/Contact.hpp"
namespace wms {
class Supplier {
    std::string name_;
    core::Address address_;
    core::Contact contact_;
public:
    Supplier(std::string name, core::Address address, const core::Contact& contact)
        : name_(std::move(name)), address_(address), contact_(contact) {}
    const std::string& name() const noexcept { return name_; }
};
}
