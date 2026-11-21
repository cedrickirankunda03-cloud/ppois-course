#pragma once
#include <string>
#include <vector>
#include "../core/SKU.hpp"
#include "../core/Quantity.hpp"
namespace wms {
class CycleCount {
    std::string zoneId_;
    std::vector<core::SKU> countedSkus_;
public:
    explicit CycleCount(std::string zoneId) : zoneId_(std::move(zoneId)) {}
    void recordCount(const core::SKU& sku) { countedSkus_.push_back(sku); }
    size_t countedCount() const noexcept { return countedSkus_.size(); }
};
}
