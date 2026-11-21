#pragma once
#include "WarehouseException.hpp"
namespace wms {
class OrderValidationException : public WarehouseException {
public:
    explicit OrderValidationException(const std::string& msg) : WarehouseException("OrderValidation: " + msg) {}
};
}
