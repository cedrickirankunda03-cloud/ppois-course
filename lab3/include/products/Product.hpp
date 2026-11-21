#pragma once
#include <string>
#include "../core/SKU.hpp"
#include "../core/Money.hpp"
#include "ProductCategory.hpp"
namespace wms {
class Product {
    core::SKU sku_;
    std::string name_;
    core::Money price_;
    ProductCategory category_;
public:
Product(core::SKU sku, std::string name, core::Money price, const ProductCategory& category)
        : sku_(sku), name_(std::move(name)), price_(price), category_(category) {}
    const core::SKU& sku() const noexcept { return sku_; }
    const std::string& name() const noexcept { return name_; }
    core::Money price() const noexcept { return price_; }
};
}
