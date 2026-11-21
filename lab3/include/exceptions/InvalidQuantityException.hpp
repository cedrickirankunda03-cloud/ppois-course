#pragma once
#include "WarehouseException.hpp"
namespace wms {
class InvalidQuantityException : public WarehouseException {
public:
    explicit InvalidQuantityException(const std::string& msg) : WarehouseException("InvalidQuantity: " + msg) {}
};
}
