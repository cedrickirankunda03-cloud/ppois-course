# Lab 3 — Warehouse Management System (WMS)

Large-scale OOP project for the "Design of Intelligent Systems Software" course.

## Subject Domain
A comprehensive Warehouse Management System handling physical storage layout, inventory tracking, order fulfillment, staff scheduling, and analytics.

## Project Structure
- `include/exceptions/` — 14 custom exception classes
- `include/core/` — Value types and identity (`SKU`, `Money`, `Quantity`, `Address`, etc.)
- `include/warehouse/` — Physical layout (`Warehouse`, `StorageZone`, `Rack`, `Shelf`, `Bin`)
- `include/products/` — Catalog and stock (`Product`, `StockItem`, `Batch`, `Supplier`)
- `include/operations/` — Order flow (`Order`, `PickList`, `Shipment`, `CycleCount`)
- `include/employees/` — Staff and shifts (`Employee`, `Picker`, `ShiftSchedule`)
- `include/analytics/` — Services and reports (`Inventory`, `InventoryService`)

## Quantitative Requirements Met
- **Classes:** 59
- **Fields:** ~196
- **Behaviors:** ~178
- **Associations:** ~56
- **Exceptions:** 14

## Build & Test (from console)

```bash
# 1. Configure the project (enables coverage and tests)
cmake -B build -DENABLE_COVERAGE=ON -DBUILD_TESTS=ON -DCMAKE_BUILD_TYPE=Debug

# 2. Build the library, CLI, and tests
cmake --build build

# 3. Run the unit tests
cd build
ctest --output-on-failure