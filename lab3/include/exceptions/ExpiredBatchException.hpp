#pragma once
#include "WarehouseException.hpp"
namespace wms {
class ExpiredBatchException : public WarehouseException {
public:
    explicit ExpiredBatchException(const std::string& msg) : WarehouseException("ExpiredBatch: " + msg) {}
};
}
