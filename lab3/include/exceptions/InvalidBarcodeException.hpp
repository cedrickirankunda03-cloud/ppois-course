#pragma once
#include "WarehouseException.hpp"
namespace wms {
class InvalidBarcodeException : public WarehouseException {
public:
    explicit InvalidBarcodeException(const std::string& msg) : WarehouseException("InvalidBarcode: " + msg) {}
};
}
