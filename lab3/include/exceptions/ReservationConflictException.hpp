#pragma once
#include "WarehouseException.hpp"
namespace wms {
class ReservationConflictException : public WarehouseException {
public:
    explicit ReservationConflictException(const std::string& msg) : WarehouseException("ReservationConflict: " + msg) {}
};
}
