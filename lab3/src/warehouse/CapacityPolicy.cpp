#include "warehouse/CapacityPolicy.hpp"
namespace wms {
CapacityPolicy::CapacityPolicy(core::Quantity maxCapacity) : maxCapacity_(maxCapacity) {}
bool CapacityPolicy::canAccommodate(const core::Quantity& incoming) const {
    return incoming.units() <= maxCapacity_.units();
}
}
