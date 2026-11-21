#pragma once
#include <vector>
#include "Shift.hpp"
#include "Employee.hpp"
namespace wms {
class ShiftSchedule {
    std::vector<Shift> shifts_;
public:
    void addShift(const Shift& shift) { shifts_.push_back(shift); }
    size_t shiftCount() const noexcept { return shifts_.size(); }
};
}
