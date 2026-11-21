#include <gtest/gtest.h>
#include "warehouse/Warehouse.hpp"
#include "exceptions/CapacityExceededException.hpp"
#include "exceptions/InvalidQuantityException.hpp"

using namespace wms;
using namespace wms::core;

TEST(WarehouseTest, BinCapacityLogic) {
    CapacityPolicy policy(Quantity(100));
    Bin bin("B-01", policy);
    
    EXPECT_EQ(bin.availableSpace().units(), 100u);
    bin.addStock(Quantity(40));
    EXPECT_EQ(bin.availableSpace().units(), 60u);
    
    EXPECT_THROW(bin.addStock(Quantity(70)), CapacityExceededException);
    EXPECT_THROW(bin.removeStock(Quantity(100)), InvalidQuantityException);
}

TEST(WarehouseTest, CompositionHierarchy) {
    Bin bin("B-01", CapacityPolicy(Quantity(50)));
    Shelf shelf("S-01");
    shelf.addBin(bin);
    
    Rack rack("R-01");
    rack.addShelf(shelf);
    
    StorageZone zone("Zone A", ZoneType::Storage);
    zone.addRack(rack);
    
    WarehouseLayout layout("Main Layout");
    layout.addZone(zone);
    
    EXPECT_EQ(shelf.binCount(), 1);
    EXPECT_EQ(rack.shelfCount(), 1);
    EXPECT_EQ(zone.rackCount(), 1);
    EXPECT_EQ(layout.zoneCount(), 1);
}
