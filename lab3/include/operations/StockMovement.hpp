#pragma once
#include "../core/SKU.hpp"
#include "../core/Quantity.hpp"
#include <string>
namespace wms {
class StockMovement {
    core::SKU sku_;
    core::Quantity amount_;
    std::string reason_;
public:
    StockMovement(core::SKU sku, core::Quantity amount, std::string reason) : sku_(sku), amount_(amount), reason_(std::move(reason)) {}
};
}
