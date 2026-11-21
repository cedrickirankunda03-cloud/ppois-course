#include <gtest/gtest.h>
#include "products/StockItem.hpp"
#include "products/PurchaseOrder.hpp"

using namespace wms;
using namespace wms::core;

TEST(ProductsTest, StockAndBatch) {
    ProductCategory cat("Electronics");
    Product p(SKU("ELE-1234"), "Laptop", Money(100000), cat);
    Lot lot("LOT-999");
    Batch batch(lot, std::chrono::system_clock::now() + std::chrono::hours(24));
    StockItem item(p, batch, Quantity(10));
    
    EXPECT_EQ(item.quantity().units(), 10u);
    EXPECT_FALSE(batch.isExpired(std::chrono::system_clock::now()));
}

TEST(ProductsTest, PurchaseOrderCalculation) {
    ProductCategory cat("Electronics");
    Product p(SKU("ELE-1234"), "Laptop", Money(100000), cat);
    
    Address addr("123 Main", "Berlin", "10115", "Germany");
    Contact contact("supplier@example.com", "+49123456");
    Supplier supplier("Tech Corp", addr, contact);
    
    PurchaseOrder po(supplier);
    po.addLine(PurchaseOrderLine(p, Quantity(2)));
    
    EXPECT_EQ(po.total().cents(), 200000);
}
