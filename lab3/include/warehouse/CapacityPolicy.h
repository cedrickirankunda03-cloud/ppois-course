#pragma once
#include "../core/Quantity.hpp"

namespace wms {

class CapacityPolicy {
    core::Quantity maxCapacity_;
public:
    explicit CapacityPolicy(core::Quantity maxCapacity);
    
    bool canAccommodate(const core::Quantity& incoming) const;
    core::Quantity maxCapacity() const noexcept { return maxCapacity_; }
};

} // namespace wms