#pragma once
#include "Carrier.hpp"
#include "DeliveryRoute.hpp"
#include "../exceptions/ShipmentException.hpp"
namespace wms {
class Shipment {
    Carrier carrier_;
    DeliveryRoute route_;
    bool isDispatched_;
public:
    Shipment(Carrier carrier, DeliveryRoute route) : carrier_(carrier), route_(route), isDispatched_(false) {}
    void dispatch() {
        if (isDispatched_) throw ShipmentException("Already dispatched");
        isDispatched_ = true;
    }
    bool isDispatched() const noexcept { return isDispatched_; }
};
}
