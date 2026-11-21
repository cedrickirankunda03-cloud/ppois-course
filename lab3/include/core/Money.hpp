#pragma once
#include <cstdint>
namespace wms { namespace core {
class Money {
    std::int64_t cents_;
public:
    explicit Money(std::int64_t cents = 0);
    std::int64_t cents() const noexcept { return cents_; }
    Money operator+(const Money& other) const;
    Money operator-(const Money& other) const;
    Money operator*(int multiplier) const;
    bool operator==(const Money& other) const noexcept { return cents_ == other.cents_; }
    bool operator<(const Money& other) const noexcept { return cents_ < other.cents_; }
    bool operator>(const Money& other) const noexcept { return other < *this; }
};
}}
