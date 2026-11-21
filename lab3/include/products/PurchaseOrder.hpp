#pragma once

#include "Supplier.hpp"

class PurchaseOrder {
private:
    Supplier supplier_;

public:
    explicit PurchaseOrder(const Supplier& supplier)
        : supplier_(supplier) {}
};
