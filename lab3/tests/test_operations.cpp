#include <gtest/gtest.h>
#include "operations/Order.hpp"
#include "operations/Shipment.hpp"
#include "products/Product.hpp"

using namespace wms;
using namespace wms::core;

TEST(OperationsTest, OrderFlow) {
    ProductCategory cat("Test");
    Product p(SKU("ABC-1234"), "Item", Money(500), cat);
    
    Order order("ORD-001");
    order.addLine(OrderLine(p, Quantity(2)));
    
    EXPECT_EQ(order.total().cents(), 1000);
    EXPECT_EQ(order.status(), OrderStatus::Created);
    
    order.markValidated();
    EXPECT_EQ(order.status(), OrderStatus::Validated);
    
    EXPECT_THROW(order.addLine(OrderLine(p, Quantity(1))), OrderValidationException);
}

TEST(OperationsTest, ShipmentDispatch) {
    Carrier carrier("FedEx");
    DeliveryRoute route("Berlin");
    Shipment shipment(carrier, route);
    
    EXPECT_FALSE(shipment.isDispatched());
    shipment.dispatch();
    EXPECT_TRUE(shipment.isDispatched());
    
    EXPECT_THROW(shipment.dispatch(), ShipmentException);
}
