#pragma once
#include <string>
#include "../core/SKU.hpp"
#include "../core/Quantity.hpp"
namespace wms {
class StockReservation {
    core::SKU sku_;
    core::Quantity quantity_;
    std::string orderId_;
public:
    StockReservation(core::SKU sku, core::Quantity qty, std::string orderId) : sku_(sku), quantity_(qty), orderId_(std::move(orderId)) {}
    const std::string& orderId() const noexcept { return orderId_; }
    const core::SKU& sku() const noexcept { return sku_; }
    const core::Quantity& quantity() const noexcept { return quantity_; }
};
}
