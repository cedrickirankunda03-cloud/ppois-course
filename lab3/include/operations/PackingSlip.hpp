#pragma once
#include <string>
namespace wms {
class PackingSlip {
    std::string orderId_;
public:
    explicit PackingSlip(std::string orderId) : orderId_(std::move(orderId)) {}
    const std::string& orderId() const noexcept { return orderId_; }
};
}
