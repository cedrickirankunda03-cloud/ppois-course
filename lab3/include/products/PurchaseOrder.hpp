#pragma once

#include "Supplier.hpp"
#include "Product.hpp"
#include "../core/Quantity.hpp"
#include "../core/Money.hpp"

#include <vector>

namespace wms {

class PurchaseOrderLine {
private:
    Product product_;
    core::Quantity quantity_;

public:
    PurchaseOrderLine(const Product& product, const core::Quantity& quantity)
        : product_(product), quantity_(quantity) {}

    core::Money total() const {
        return product_.price() * static_cast<int>(quantity_.units());
    }
};

class PurchaseOrder {
private:
    Supplier supplier_;
    std::vector<PurchaseOrderLine> lines_;

public:
    explicit PurchaseOrder(const Supplier& supplier)
        : supplier_(supplier) {}

    void addLine(const PurchaseOrderLine& line) {
        lines_.push_back(line);
    }

    core::Money total() const {
        core::Money result(0);

        for (const auto& line : lines_) {
            result = result + line.total();
        }

        return result;
    }
};

}
