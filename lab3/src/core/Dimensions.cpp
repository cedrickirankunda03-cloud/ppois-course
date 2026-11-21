#include "core/Dimensions.hpp"
#include "exceptions/InvalidQuantityException.hpp"
namespace wms { namespace core {
Dimensions::Dimensions(std::uint32_t lengthMm, std::uint32_t widthMm, std::uint32_t heightMm)
    : lengthMm_(lengthMm), widthMm_(widthMm), heightMm_(heightMm) {
    if (lengthMm_ == 0 || widthMm_ == 0 || heightMm_ == 0) throw InvalidQuantityException("dimension must be positive");
}
std::uint64_t Dimensions::volumeMm3() const noexcept { return static_cast<std::uint64_t>(lengthMm_) * widthMm_ * heightMm_; }
bool Dimensions::fitsInside(const Dimensions& outer) const noexcept { return lengthMm_ <= outer.lengthMm_ && widthMm_ <= outer.widthMm_ && heightMm_ <= outer.heightMm_; }
}}
