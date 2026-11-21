#pragma once
#include <vector>
#include <memory>
#include <string>
#include "../products/StockItem.hpp"
#include "../operations/StockReservation.hpp"
#include "../exceptions/InsufficientStockException.hpp"
namespace wms {
class Inventory {
    std::vector<std::shared_ptr<StockItem>> items_;
    std::vector<StockReservation> reservations_;
public:
    void receive(std::shared_ptr<StockItem> item) { items_.push_back(item); }
    core::Quantity onHand(const core::SKU& sku) const {
        std::uint32_t total = 0;
        for (const auto& it : items_) if (it->product().sku() == sku) total += it->quantity().units();
        return core::Quantity(total);
    }
    core::Quantity available(const core::SKU& sku) const {
        std::uint32_t reserved = 0;
        for (const auto& r : reservations_) if (r.sku() == sku) reserved += r.quantity().units();
        std::uint32_t avail = onHand(sku).units();
        return core::Quantity(reserved > avail ? 0 : avail - reserved);
    }
    void reserve(const core::SKU& sku, core::Quantity qty, const std::string& orderId) {
        if (available(sku) < qty) throw InsufficientStockException("Not enough available stock");
        reservations_.push_back(StockReservation(sku, qty, orderId));
    }
};
}
