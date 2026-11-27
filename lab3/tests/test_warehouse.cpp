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

TEST(WarehouseTest, WarehouseConstructionAndGetters) {
    StorageZone zone("Storage Zone", ZoneType::Storage);
    WarehouseLayout layout("Main Layout");
    layout.addZone(zone);

    Address address("Main Street", "Berlin", "10115", "Germany");
    Warehouse warehouse("Central Warehouse", address, layout);

    EXPECT_EQ(warehouse.name(), "Central Warehouse");
    EXPECT_EQ(warehouse.layout().layoutName(), "Main Layout");
    EXPECT_EQ(warehouse.layout().zoneCount(), 1);
}

TEST(WarehouseTest, HasExistingZoneType) {
    WarehouseLayout layout("Layout");

    layout.addZone(StorageZone("Storage", ZoneType::Storage));
    layout.addZone(StorageZone("Picking", ZoneType::Picking));

    Address address("Street", "Berlin", "10115", "Germany");
    Warehouse warehouse("Warehouse", address, layout);

    EXPECT_TRUE(warehouse.hasZoneOfType(ZoneType::Storage));
    EXPECT_TRUE(warehouse.hasZoneOfType(ZoneType::Picking));
}

TEST(WarehouseTest, ReturnsFalseForMissingZoneType) {
    WarehouseLayout layout("Layout");

    layout.addZone(StorageZone("Storage", ZoneType::Storage));

    Address address("Street", "Berlin", "10115", "Germany");
    Warehouse warehouse("Warehouse", address, layout);

    EXPECT_FALSE(warehouse.hasZoneOfType(ZoneType::Receiving));
    EXPECT_FALSE(warehouse.hasZoneOfType(ZoneType::Shipping));
}

TEST(WarehouseTest, SupportsMultipleZoneTypes) {
    WarehouseLayout layout("Complete Layout");

    layout.addZone(StorageZone("Receiving Area", ZoneType::Receiving));
    layout.addZone(StorageZone("Storage Area", ZoneType::Storage));
    layout.addZone(StorageZone("Picking Area", ZoneType::Picking));
    layout.addZone(StorageZone("Packing Area", ZoneType::Packing));
    layout.addZone(StorageZone("Shipping Area", ZoneType::Shipping));

    Address address("Warehouse Road", "Berlin", "10115", "Germany");
    Warehouse warehouse("Complete Warehouse", address, layout);

    EXPECT_TRUE(warehouse.hasZoneOfType(ZoneType::Receiving));
    EXPECT_TRUE(warehouse.hasZoneOfType(ZoneType::Storage));
    EXPECT_TRUE(warehouse.hasZoneOfType(ZoneType::Picking));
    EXPECT_TRUE(warehouse.hasZoneOfType(ZoneType::Packing));
    EXPECT_TRUE(warehouse.hasZoneOfType(ZoneType::Shipping));
}


