#pragma once
#include "WarehouseException.hpp"
namespace wms {
class EquipmentUnavailableException : public WarehouseException {
public:
    explicit EquipmentUnavailableException(const std::string& msg) : WarehouseException("EquipmentUnavailable: " + msg) {}
};
}
