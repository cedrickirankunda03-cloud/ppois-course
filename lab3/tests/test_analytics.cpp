#include <gtest/gtest.h>
#include "analytics/OrderService.hpp"
#include "analytics/InventoryService.hpp"
#include "products/Product.hpp"

using namespace wms;
using namespace wms::core;

TEST(AnalyticsTest, InventoryReservation) {
    Inventory inv;
    ProductCategory cat("Test");
    Product p(SKU("ABC-1234"), "Item", Money(100), cat);
    Lot lot("L1");
    Batch batch(lot, std::chrono::system_clock::now() + std::chrono::hours(24));
    
    auto item = std::make_shared<StockItem>(p, batch, Quantity(10));
    inv.receive(item);
    
    EXPECT_EQ(inv.onHand(p.sku()).units(), 10u);
    
    inv.reserve(p.sku(), Quantity(5), "ORD-1");
    
    EXPECT_THROW(inv.reserve(p.sku(), Quantity(6), "ORD-2"), InsufficientStockException);
}
