#include "core/Weight.hpp"
namespace wms { namespace core {
Weight::Weight(std::uint32_t grams) : grams_(grams) {}
double Weight::kilograms() const noexcept { return grams_ / 1000.0; }
Weight Weight::operator+(const Weight& other) const { return Weight(grams_ + other.grams_); }
}}
