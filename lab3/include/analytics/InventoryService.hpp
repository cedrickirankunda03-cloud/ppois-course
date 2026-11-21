#pragma once
#include "Inventory.hpp"
namespace wms {
class InventoryService {
    Inventory& inventory_;
public:
    explicit InventoryService(Inventory& inv) : inventory_(inv) {}
    void processDelivery(std::shared_ptr<StockItem> item) { inventory_.receive(item); }
};
}
