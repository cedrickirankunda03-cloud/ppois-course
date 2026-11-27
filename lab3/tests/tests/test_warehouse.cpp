#include <gtest/gtest.h>
#include "warehouse/Warehouse.hpp"
#include "exceptions/CapacityExceededException.hpp"
#include "exceptions/InvalidQuantityException.hpp"

using namespace wms;

TEST(WarehouseTest, BinCapacityLogic) {
    CapacityPolicy policy(core::Quantity(100));
    Bin bin("B-01", policy);
    
    EXPECT_EQ(bin.availableSpace().units(), 100u);
    
    bin.addStock(core::Quantity(40));
    EXPECT_EQ(bin.availableSpace().units(), 60u);
    
    // Test exception when adding too much
    EXPECT_THROW(bin.addStock(core::Quantity(70)), CapacityExceededException);
    
    bin.removeStock(core::Quantity(10));
    EXPECT_EQ(bin.availableSpace().units(), 70u);
    
    // Test exception when removing too much
    EXPECT_THROW(bin.removeStock(core::Quantity(100)), InvalidQuantityException);
}

TEST(WarehouseTest, CompositionHierarchy) {
    // Build the hierarchy bottom-up
    Bin bin("B-01", CapacityPolicy(core::Quantity(50)));
    Shelf shelf("S-01");
    shelf.addBin(bin);
    
    Rack rack("R-01");
    rack.addShelf(shelf);
    
    StorageZone zone("Zone A", ZoneType::Storage);
    zone.addRack(rack);
    
    WarehouseLayout layout("Main Layout");
    layout.addZone(zone);
    
    // Assert the tree is built correctly
    EXPECT_EQ(shelf.binCount(), 1);
    EXPECT_EQ(rack.shelfCount(), 1);
    EXPECT_EQ(zone.rackCount(), 1);
    EXPECT_EQ(layout.zoneCount(), 1);
}

TEST(WarehouseTest, WarehouseHasZoneOfType) {
    core::Address addr("123 Main", "Berlin", "10115", "Germany");
    
    StorageZone storage("Storage A", ZoneType::Storage);
    WarehouseLayout layout("Main Layout");
    layout.addZone(storage);
    
    Warehouse warehouse("Central WMS", addr, layout);
    
    EXPECT_TRUE(warehouse.hasZoneOfType(ZoneType::Storage));
    EXPECT_FALSE(warehouse.hasZoneOfType(ZoneType::Shipping));
}