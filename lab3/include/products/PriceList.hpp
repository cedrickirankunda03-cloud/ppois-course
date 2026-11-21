#pragma once
#include <vector>
#include "Product.hpp"
namespace wms {
class PriceList {
    std::vector<Product> products_;
public:
    void addProduct(const Product& p) { products_.push_back(p); }
    core::Money calculateTotal() const {
        core::Money sum(0);
        for (const auto& p : products_) sum = sum + p.price();
        return sum;
    }
};
}
