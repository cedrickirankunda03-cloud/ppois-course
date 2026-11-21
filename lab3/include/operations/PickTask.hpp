#pragma once
#include <string>
#include "../core/Quantity.hpp"
namespace wms {
class PickTask {
    std::string binId_;
    core::SKU sku_;
    core::Quantity quantity_;
public:
    PickTask(std::string binId, core::SKU sku, core::Quantity qty) : binId_(binId), sku_(sku), quantity_(qty) {}
    const std::string& binId() const noexcept { return binId_; }
};
}
