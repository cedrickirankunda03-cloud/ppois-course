#pragma once
#include <string>
#include "../core/Quantity.hpp"
#include "CapacityPolicy.hpp"
namespace wms {
class Bin {
    std::string id_;
    CapacityPolicy capacity_;
    core::Quantity currentFill_;
public:
    Bin(std::string id, CapacityPolicy capacity);
    const std::string& id() const noexcept { return id_; }
    core::Quantity availableSpace() const;
    void addStock(const core::Quantity& amount);
    void removeStock(const core::Quantity& amount);
};
}
