#pragma once
#include <string>
#include "WarehouseLayout.hpp"
#include "../core/Address.hpp"

namespace wms {

class Warehouse {
    std::string name_;
    core::Address address_;
    WarehouseLayout layout_;
public:
    Warehouse(std::string name, core::Address address, WarehouseLayout layout);
    
    const std::string& name() const noexcept { return name_; }
    const core::Address& address() const noexcept { return address_; }
    const WarehouseLayout& layout() const noexcept { return layout_; }
    
    // Behavior example: checking if a zone type exists
    bool hasZoneOfType(ZoneType type) const;
};

} // namespace wms