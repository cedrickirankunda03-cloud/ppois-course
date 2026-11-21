#pragma once
#include "WarehouseException.hpp"
namespace wms {
class InsufficientStockException : public WarehouseException {
public:
    explicit InsufficientStockException(const std::string& msg) : WarehouseException("InsufficientStock: " + msg) {}
};
}
