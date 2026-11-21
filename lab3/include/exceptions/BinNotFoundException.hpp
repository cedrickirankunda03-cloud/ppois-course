#pragma once
#include "WarehouseException.hpp"
namespace wms {
class BinNotFoundException : public WarehouseException {
public:
    explicit BinNotFoundException(const std::string& msg) : WarehouseException("BinNotFound: " + msg) {}
};
}
