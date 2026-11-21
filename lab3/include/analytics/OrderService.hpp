#pragma once
#include "../operations/Order.hpp"
#include "Inventory.hpp"
#include "../exceptions/InsufficientStockException.hpp"
namespace wms {
class OrderService {
    Inventory& inventory_;
public:
    explicit OrderService(Inventory& inv) : inventory_(inv) {}
    void validateOrder(const Order& order) {
        for (const auto& line : order.lines()) {
            if (inventory_.onHand(line.sku()) < line.quantity()) throw InsufficientStockException("Missing stock");
        }
    }
};
}
