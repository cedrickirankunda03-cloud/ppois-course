#pragma once
#include "WarehouseException.hpp"
namespace wms {
class ShipmentException : public WarehouseException {
public:
    explicit ShipmentException(const std::string& msg) : WarehouseException("Shipment: " + msg) {}
};
}
