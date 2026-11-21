#pragma once
#include <string>
namespace wms { namespace core {
class SKU {
    std::string code_;
public:
    explicit SKU(std::string code);
    const std::string& value() const noexcept { return code_; }
    bool operator==(const SKU& other) const noexcept { return code_ == other.code_; }
    bool operator!=(const SKU& other) const noexcept { return !(*this == other); }
    bool operator<(const SKU& other) const noexcept { return code_ < other.code_; }
};
}}
