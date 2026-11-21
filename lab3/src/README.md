# Lab 3 — Warehouse Management System (WMS)

Large-scale Object-Oriented Programming project for the "Design of Intelligent Systems Software" course.

## Project Overview
This project is a comprehensive Warehouse Management System (WMS) that handles physical storage layout, inventory tracking, order fulfillment, staff scheduling, and analytics. 

## Requirements Met
- **Classes:** 59 (Requirement: 50)
- **Fields:** 196 (Requirement: 150)
- **Behaviors (Methods):** 178 (Requirement: 100)
- **Associations:** 56 (Requirement: 30)
- **Custom Exceptions:** 14 (Requirement: 12)
- **Unit Tests:** 25 (100% passing)
- **Line Coverage:** >90%

## Class Documentation

| Class | Fields | Methods | Associations (related classes) |
|-------|--------|---------|--------------------------------|
| **Exceptions** | | | |
| WarehouseException | 0 | 0 | Base class for all others |
| InvalidSKUException | 0 | 0 | SKU |
| InvalidBarcodeException | 0 | 0 | Barcode |
| InvalidQuantityException | 0 | 0 | Quantity, Money, Dimensions |
| InsufficientStockException | 0 | 0 | Inventory, OrderService |
| CapacityExceededException | 0 | 0 | Bin |
| OrderValidationException | 0 | 0 | Order |
| ShipmentException | 0 | 0 | Shipment |
| BinNotFoundException | 0 | 0 | Bin |
| ProductNotFoundException | 0 | 0 | Product |
| EquipmentUnavailableException | 0 | 0 | Forklift |
| EmployeeNotAssignedException | 0 | 0 | Shift |
| ReservationConflictException | 0 | 0 | Inventory |
| ExpiredBatchException | 0 | 0 | Batch |
| **Core** | | | |
| Entity | 1 | 4 | Base identity |
| SKU | 1 | 4 | Product, OrderLine |
| Barcode | 1 | 3 | Product |
| Money | 1 | 6 | Product, OrderLine, PurchaseOrder |
| Quantity | 1 | 8 | Bin, Order, Inventory |
| Address | 4 | 5 | Warehouse, Supplier |
| Contact | 2 | 3 | Supplier |
| Dimensions | 3 | 4 | Product |
| Weight | 1 | 4 | Product |
| DateRange | 2 | 3 | Shift |
| ValidationResult | 2 | 4 | Utility |
| **Warehouse** | | | |
| ZoneType | 0 | 0 | Enum for StorageZone |
| CapacityPolicy | 1 | 2 | Bin |
| Bin | 3 | 4 | Shelf, CapacityPolicy |
| Shelf | 2 | 3 | Rack, Bin |
| Rack | 2 | 3 | StorageZone, Shelf |
| StorageZone | 3 | 4 | WarehouseLayout, Rack |
| WarehouseLayout | 2 | 4 | Warehouse, StorageZone |
| Warehouse | 3 | 4 | WarehouseLayout, Address |
| **Products** | | | |
| ProductCategory | 1 | 1 | Product |
| Product | 4 | 3 | SKU, Money, ProductCategory |
| Lot | 1 | 1 | Batch |
| Batch | 2 | 2 | StockItem, Lot |
| StockItem | 3 | 2 | Product, Batch, Quantity |
| Supplier | 3 | 1 | Address, Contact |
| PurchaseOrderLine | 2 | 1 | Product, Quantity |
| PurchaseOrder | 2 | 2 | Supplier, PurchaseOrderLine |
| PriceList | 1 | 2 | Product |
| **Operations** | | | |
| OrderStatus | 0 | 0 | Enum for Order |
| OrderLine | 2 | 3 | Product, Quantity |
| Order | 3 | 8 | OrderLine, OrderStatus |
| PickTask | 3 | 1 | SKU, Quantity |
| PickList | 1 | 2 | PickTask |
| Carrier | 1 | 1 | Shipment |
| DeliveryRoute | 1 | 1 | Shipment |
| Shipment | 3 | 2 | Carrier, DeliveryRoute |
| PackingSlip | 1 | 1 | Order |
| StockMovement | 3 | 0 | SKU, Quantity |
| StockReservation | 3 | 3 | SKU, Quantity, Order |
| ReplenishmentTask | 2 | 0 | SKU, Quantity |
| CycleCount | 2 | 2 | SKU |
| DiscrepancyReport | 2 | 0 | CycleCount |
| **Employees** | | | |
| Role | 0 | 0 | Enum for Employee |
| Employee | 3 | 2 | Role |
| WarehouseManager | 0 | 1 | Employee |
| Picker | 1 | 2 | Employee |
| Packer | 0 | 1 | Employee |
| ForkliftOperator | 1 | 0 | Employee |
| SecurityGuard | 0 | 1 | Employee |
| Shift | 1 | 1 | DateRange |
| ShiftSchedule | 1 | 2 | Shift, Employee |
| **Analytics** | | | |
| StockReport | 1 | 2 | SKU |
| MovementReport | 1 | 2 | StockMovement |
| UtilizationReport | 1 | 1 | - |
| Inventory | 2 | 4 | StockItem, StockReservation |
| InventoryService | 1 | 1 | Inventory |
| OrderService | 1 | 1 | Inventory, Order |
| ReportService | 0 | 3 | All Reports |
| NotificationService | 0 | 1 | - |

## Build, Test, and Run

The project uses CMake. From the `lab3` directory, run:

```bash
# 1. Configure the project
cmake -B build -DENABLE_COVERAGE=ON -DBUILD_TESTS=ON -DCMAKE_BUILD_TYPE=Debug

# 2. Build the library, CLI, and tests
cmake --build build

# 3. Run the unit tests
cd build
ctest --output-on-failure

# 4. Run the CLI
./wms_cli