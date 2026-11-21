#include "warehouse/WarehouseLayout.hpp"
namespace wms {
WarehouseLayout::WarehouseLayout(std::string layoutName) : layoutName_(std::move(layoutName)) {}
void WarehouseLayout::addZone(const StorageZone& zone) { zones_.push_back(zone); }
}
