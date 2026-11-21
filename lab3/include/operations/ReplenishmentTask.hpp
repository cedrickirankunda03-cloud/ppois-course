#pragma once
#include "../core/SKU.hpp"
#include "../core/Quantity.hpp"
namespace wms {
class ReplenishmentTask {
    core::SKU sku_;
    core::Quantity deficit_;
public:
    ReplenishmentTask(core::SKU sku, core::Quantity deficit) : sku_(sku), deficit_(deficit) {}
};
}
