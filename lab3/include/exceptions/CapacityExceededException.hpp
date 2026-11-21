#pragma once
#include "WarehouseException.hpp"
namespace wms {
class CapacityExceededException : public WarehouseException {
public:
    explicit CapacityExceededException(const std::string& msg) : WarehouseException("CapacityExceeded: " + msg) {}
};
}
