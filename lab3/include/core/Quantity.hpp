#pragma once
#include <cstdint>
namespace wms { namespace core {
class Quantity {
    std::uint32_t units_;
public:
    explicit Quantity(std::uint32_t units = 0);
    std::uint32_t units() const noexcept { return units_; }
    bool isZero() const noexcept { return units_ == 0; }
    Quantity operator+(const Quantity& other) const;
    Quantity operator-(const Quantity& other) const;
    bool operator==(const Quantity& other) const noexcept { return units_ == other.units_; }
    bool operator<(const Quantity& other) const noexcept { return units_ < other.units_; }
    bool operator<=(const Quantity& other) const noexcept { return units_ <= other.units_; }
    bool operator>=(const Quantity& other) const noexcept { return units_ >= other.units_; }
};
}}
