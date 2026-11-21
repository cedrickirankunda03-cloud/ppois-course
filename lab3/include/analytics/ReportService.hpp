#pragma once
#include "StockReport.hpp"
#include "MovementReport.hpp"
#include "UtilizationReport.hpp"
namespace wms {
class ReportService {
public:
    StockReport generateStockReport() { return StockReport(); }
    MovementReport generateMovementReport() { return MovementReport(); }
    UtilizationReport generateUtilizationReport(double percent) { return UtilizationReport(percent); }
};
}
