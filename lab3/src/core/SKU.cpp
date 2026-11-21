#include "core/SKU.hpp"
#include "exceptions/InvalidSKUException.hpp"
#include <regex>
namespace wms { namespace core {
SKU::SKU(std::string code) : code_(std::move(code)) {
    static const std::regex pattern(R"(^[A-Z]{3}-\d{4,6}$)");
    if (!std::regex_match(code_, pattern)) throw InvalidSKUException("bad format: '" + code_ + "'");
}
}}
