#pragma once
#include <cstdint>
namespace wms { namespace core {
class Weight {
    std::uint32_t grams_;
public:
    explicit Weight(std::uint32_t grams = 0);
    std::uint32_t grams() const noexcept { return grams_; }
    double kilograms() const noexcept;
    Weight operator+(const Weight& other) const;
    bool operator==(const Weight& other) const noexcept { return grams_ == other.grams_; }
    bool operator<(const Weight& other) const noexcept { return grams_ < other.grams_; }
    bool operator>(const Weight& other) const noexcept { return other < *this; }
};
}}
