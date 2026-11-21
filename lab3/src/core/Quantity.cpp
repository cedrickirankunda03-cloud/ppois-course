#include "core/Quantity.hpp"
#include "exceptions/InvalidQuantityException.hpp"
namespace wms { namespace core {
Quantity::Quantity(std::uint32_t units) : units_(units) {}
Quantity Quantity::operator+(const Quantity& other) const { return Quantity(units_ + other.units_); }
Quantity Quantity::operator-(const Quantity& other) const {
    if (other.units_ > units_) throw InvalidQuantityException("quantity underflow");
    return Quantity(units_ - other.units_);
}
}}
