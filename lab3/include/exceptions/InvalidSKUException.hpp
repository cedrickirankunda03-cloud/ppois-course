#pragma once
#include "WarehouseException.hpp"
namespace wms {
class InvalidSKUException : public WarehouseException {
public:
    explicit InvalidSKUException(const std::string& msg) : WarehouseException("InvalidSKU: " + msg) {}
};
}
