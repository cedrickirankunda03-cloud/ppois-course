#pragma once
#include <stdexcept>
#include <string>
namespace wms {
class WarehouseException : public std::runtime_error {
public:
    explicit WarehouseException(const std::string& msg) : std::runtime_error(msg) {}
};
}
