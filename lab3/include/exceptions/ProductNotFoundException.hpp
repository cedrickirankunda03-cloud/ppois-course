#pragma once
#include "WarehouseException.hpp"
namespace wms {
class ProductNotFoundException : public WarehouseException {
public:
    explicit ProductNotFoundException(const std::string& msg) : WarehouseException("ProductNotFound: " + msg) {}
};
}
