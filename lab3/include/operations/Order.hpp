#pragma once
#include <string>
#include <vector>
#include "OrderStatus.hpp"
#include "OrderLine.hpp"
#include "../exceptions/OrderValidationException.hpp"
namespace wms {
class Order {
    std::string id_;
    std::vector<OrderLine> lines_;
    OrderStatus status_;
public:
    explicit Order(std::string id) : id_(std::move(id)), status_(OrderStatus::Created) {}
    void addLine(const OrderLine& line) {
        if (status_ != OrderStatus::Created) throw OrderValidationException("Cannot add lines after creation");
        lines_.push_back(line);
    }
    void markValidated() { status_ = OrderStatus::Validated; }
    void markPicked() { status_ = OrderStatus::Picked; }
    void markShipped() { status_ = OrderStatus::Shipped; }
    core::Money total() const {
        core::Money sum(0);
        for (const auto& l : lines_) sum = sum + l.total();
        return sum;
    }
    OrderStatus status() const noexcept { return status_; }
    
    // ADDED THIS GETTER
    const std::vector<OrderLine>& lines() const noexcept { return lines_; }
};
}
