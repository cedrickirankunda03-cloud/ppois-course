#pragma once
#include <vector>
#include "../core/SKU.hpp"
#include "../core/Quantity.hpp"
namespace wms {
class StockReport {
    std::vector<core::SKU> skus_;
public:
    void addSku(const core::SKU& sku) { skus_.push_back(sku); }
    size_t skuCount() const noexcept { return skus_.size(); }
};
}
