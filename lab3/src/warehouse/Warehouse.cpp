#include "warehouse/Warehouse.hpp"
namespace wms {
Warehouse::Warehouse(std::string name, core::Address address, WarehouseLayout layout) : name_(std::move(name)), address_(std::move(address)), layout_(std::move(layout)) {}
bool Warehouse::hasZoneOfType(ZoneType type) const {
    for (const auto& zone : layout_.zones()) if (zone.type() == type) return true;
    return false;
}
}
