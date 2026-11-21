#pragma once
#include <cstdint>
namespace wms { namespace core {
class Dimensions {
    std::uint32_t lengthMm_, widthMm_, heightMm_;
public:
    Dimensions(std::uint32_t lengthMm, std::uint32_t widthMm, std::uint32_t heightMm);
    std::uint32_t lengthMm() const noexcept { return lengthMm_; }
    std::uint32_t widthMm() const noexcept { return widthMm_; }
    std::uint32_t heightMm() const noexcept { return heightMm_; }
    std::uint64_t volumeMm3() const noexcept;
    bool fitsInside(const Dimensions& outer) const noexcept;
};
}}
