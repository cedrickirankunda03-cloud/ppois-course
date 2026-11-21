#pragma once
namespace wms {
class UtilizationReport {
    double utilizationPercent_;
public:
    explicit UtilizationReport(double percent) : utilizationPercent_(percent) {}
    double percent() const noexcept { return utilizationPercent_; }
};
}
