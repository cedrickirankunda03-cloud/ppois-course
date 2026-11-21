#pragma once
#include "../products/Product.hpp"
#include "../core/Quantity.hpp"
namespace wms {
class OrderLine {
    Product product_;
    core::Quantity quantity_;
public:
    OrderLine(Product product, core::Quantity quantity) : product_(product), quantity_(quantity) {}
    core::Money total() const { return product_.price() * static_cast<int>(quantity_.units()); }
    const core::Quantity& quantity() const noexcept { return quantity_; }
    const core::SKU& sku() const noexcept { return product_.sku(); }
};
}
