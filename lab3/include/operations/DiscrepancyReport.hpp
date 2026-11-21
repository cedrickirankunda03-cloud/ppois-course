#pragma once
#include <string>
#include "CycleCount.hpp"
namespace wms {
class DiscrepancyReport {
    CycleCount count_;
    std::string notes_;
public:
    DiscrepancyReport(CycleCount count, std::string notes) : count_(count), notes_(std::move(notes)) {}
};
}
