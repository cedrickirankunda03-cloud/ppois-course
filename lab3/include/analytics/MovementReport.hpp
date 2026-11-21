#pragma once
#include <vector>
#include "../operations/StockMovement.hpp"
namespace wms {
class MovementReport {
    std::vector<StockMovement> movements_;
public:
    void record(const StockMovement& m) { movements_.push_back(m); }
    size_t movementCount() const noexcept { return movements_.size(); }
};
}
