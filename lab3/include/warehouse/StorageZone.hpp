#pragma once
#include <string>
#include <vector>
#include "Rack.hpp"
#include "ZoneType.hpp"
namespace wms {
class StorageZone {
    std::string name_;
    ZoneType type_;
    std::vector<Rack> racks_;
public:
    StorageZone(std::string name, ZoneType type);
    void addRack(const Rack& rack);
    const std::string& name() const noexcept { return name_; }
    ZoneType type() const noexcept { return type_; }
    size_t rackCount() const noexcept { return racks_.size(); }
};
}
