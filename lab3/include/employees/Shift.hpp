#pragma once
#include "../core/DateRange.hpp"
namespace wms {
class Shift {
    core::DateRange period_;
public:
    explicit Shift(core::DateRange period) : period_(period) {}
    bool isActive(std::chrono::system_clock::time_point now) const { return period_.contains(now); }
};
}
