#pragma once
#include <string>
namespace wms { namespace core {
class Barcode {
    std::string digits_;
public:
    explicit Barcode(std::string digits);
    const std::string& value() const noexcept { return digits_; }
    bool isValidChecksum() const noexcept;
    bool operator==(const Barcode& other) const noexcept { return digits_ == other.digits_; }
};
}}
