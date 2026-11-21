#include "core/Money.hpp"
#include "exceptions/InvalidQuantityException.hpp"
namespace wms { namespace core {
Money::Money(std::int64_t cents) : cents_(cents) { if (cents_ < 0) throw InvalidQuantityException("negative money amount"); }
Money Money::operator+(const Money& other) const { return Money(cents_ + other.cents_); }
Money Money::operator-(const Money& other) const {
    if (other.cents_ > cents_) throw InvalidQuantityException("subtraction would go negative");
    return Money(cents_ - other.cents_);
}
Money Money::operator*(int multiplier) const {
    if (multiplier < 0) throw InvalidQuantityException("negative multiplier");
    return Money(cents_ * multiplier);
}
}}
