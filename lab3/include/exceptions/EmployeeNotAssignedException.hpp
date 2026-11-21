#pragma once
#include "WarehouseException.hpp"
namespace wms {
class EmployeeNotAssignedException : public WarehouseException {
public:
    explicit EmployeeNotAssignedException(const std::string& msg) : WarehouseException("EmployeeNotAssigned: " + msg) {}
};
}
