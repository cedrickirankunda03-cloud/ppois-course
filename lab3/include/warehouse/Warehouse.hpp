#pragma once
#include <string>
#include "WarehouseLayout.hpp"
#include "ZoneType.hpp"
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
    bool hasZoneOfType(ZoneType type) const;
};
}
