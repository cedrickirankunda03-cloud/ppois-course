#include "core/Barcode.hpp"
#include "exceptions/InvalidBarcodeException.hpp"
#include <cctype>
namespace wms { namespace core {
Barcode::Barcode(std::string digits) : digits_(std::move(digits)) {
    if (digits_.size() != 13) throw InvalidBarcodeException("must be exactly 13 digits");
    for (char c : digits_) if (!std::isdigit(static_cast<unsigned char>(c))) throw InvalidBarcodeException("non-digit character");
}
bool Barcode::isValidChecksum() const noexcept {
    int sum = 0;
    for (int i = 0; i < 12; ++i) { int d = digits_[i] - '0'; sum += (i % 2 == 0) ? d : d * 3; }
    return ((10 - (sum % 10)) % 10) == (digits_[12] - '0');
}
}}
