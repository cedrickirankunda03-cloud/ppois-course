#pragma once
#include "Product.hpp"
#include "../core/Quantity.hpp"
namespace wms {
class PurchaseOrderLine {
    Product product_;
    core::Quantity quantity_;
public:
    PurchaseOrderLine(Product product, core::Quantity quantity) : product_(product), quantity_(quantity) {}
    core::Money total() const { return product_.price() * static_cast<int>(quantity_.units()); }
};
}
