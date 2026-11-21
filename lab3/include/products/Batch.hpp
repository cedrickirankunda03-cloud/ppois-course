#pragma once
#include <chrono>
#include "Lot.hpp"
namespace wms {
class Batch {
    Lot lot_;
    std::chrono::system_clock::time_point expiryDate_;
public:
    Batch(Lot lot, std::chrono::system_clock::time_point expiryDate) : lot_(lot), expiryDate_(expiryDate) {}
    bool isExpired(std::chrono::system_clock::time_point now) const { return now > expiryDate_; }
    const Lot& lot() const noexcept { return lot_; }
};
}
