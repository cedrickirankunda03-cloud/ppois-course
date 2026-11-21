#pragma once
#include "Product.hpp"
#include "Batch.hpp"
#include "../core/Quantity.hpp"
namespace wms {
class StockItem {
    Product product_;
    Batch batch_;
    core::Quantity quantity_;
public:
    StockItem(Product product, Batch batch, core::Quantity quantity) 
        : product_(product), batch_(batch), quantity_(quantity) {}
    const Product& product() const noexcept { return product_; }
    const core::Quantity& quantity() const noexcept { return quantity_; }
};
}
