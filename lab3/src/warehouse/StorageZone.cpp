#include "warehouse/StorageZone.hpp"
namespace wms {
StorageZone::StorageZone(std::string name, ZoneType type) : name_(std::move(name)), type_(type) {}
void StorageZone::addRack(const Rack& rack) { racks_.push_back(rack); }
}
