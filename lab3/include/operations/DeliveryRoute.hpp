#pragma once
#include <string>
namespace wms {
class DeliveryRoute {
    std::string destination_;
public:
    explicit DeliveryRoute(std::string destination) : destination_(std::move(destination)) {}
    const std::string& destination() const noexcept { return destination_; }
};
}
