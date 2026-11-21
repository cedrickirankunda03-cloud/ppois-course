#pragma once

#include "Supplier.hpp"

namespace wms {

class PurchaseOrder {
private:
    Supplier supplier_;

public:
    explicit PurchaseOrder(const Supplier& supplier)
        : supplier_(supplier) {}
};

}
