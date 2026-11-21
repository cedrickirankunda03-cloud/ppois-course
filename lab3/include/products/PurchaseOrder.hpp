#pragma once
#include <vector>
#include "Supplier.hpp"
#include "PurchaseOrderLine.hpp"
namespace wms {
class PurchaseOrder {
    Supplier supplier_;
    std::vector<PurchaseOrderLine> lines_;
public:
explicit PurchaseOrder(const Supplier& supplier)
    void addLine(const PurchaseOrderLine& line) { lines_.push_back(line); }
    core::Money total() const {
        core::Money sum(0);
        for (const auto& line : lines_) sum = sum + line.total();
        return sum;
    }
};
}
