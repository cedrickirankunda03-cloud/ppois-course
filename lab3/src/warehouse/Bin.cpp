#include "warehouse/Bin.hpp"
#include "exceptions/CapacityExceededException.hpp"
#include "exceptions/InvalidQuantityException.hpp"
#include <string>
namespace wms {
Bin::Bin(std::string id, CapacityPolicy capacity) : id_(std::move(id)), capacity_(capacity), currentFill_(0) {}
core::Quantity Bin::availableSpace() const {
    return core::Quantity(capacity_.maxCapacity().units() - currentFill_.units());
}
void Bin::addStock(const core::Quantity& amount) {
    if (!capacity_.canAccommodate(currentFill_ + amount)) throw CapacityExceededException("Bin " + id_ + " cannot hold more units.");
    currentFill_ = currentFill_ + amount;
}
void Bin::removeStock(const core::Quantity& amount) {
    if (amount.units() > currentFill_.units()) throw InvalidQuantityException("Cannot remove more stock than exists.");
    currentFill_ = currentFill_ - amount;
}
}
