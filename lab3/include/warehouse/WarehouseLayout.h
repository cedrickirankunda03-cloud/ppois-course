#pragma once
#include <string>
#include <vector>
#include "StorageZone.hpp"

namespace wms {

class WarehouseLayout {
    std::string layoutName_;
    std::vector<StorageZone> zones_;
public:
    explicit WarehouseLayout(std::string layoutName);
    
        const std::vector<StorageZone>& zones() const noexcept { return zones_; }
    
    void addZone(const StorageZone& zone);
    const std::string& layoutName() const noexcept { return layoutName_; }
    size_t zoneCount() const noexcept { return zones_.size(); }
};

} // namespace wms