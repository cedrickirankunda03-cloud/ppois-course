#include <iostream>
#include <memory>
#include <iomanip>
#include "analytics/Inventory.hpp"
#include "analytics/OrderService.hpp"
#include "analytics/ReportService.hpp"
#include "analytics/NotificationService.hpp"
#include "operations/Order.hpp"
#include "operations/Shipment.hpp"
#include "operations/CycleCount.hpp"
#include "operations/DiscrepancyReport.hpp"
#include "operations/PickList.hpp"
#include "operations/PickTask.hpp"
#include "operations/StockMovement.hpp"
#include "operations/ReplenishmentTask.hpp"
#include "products/Product.hpp"
#include "products/PurchaseOrder.hpp"
#include "products/PriceList.hpp"
#include "employees/Picker.hpp"
#include "employees/WarehouseManager.hpp"
#include "employees/SecurityGuard.hpp"
#include "employees/Shift.hpp"
#include "employees/ShiftSchedule.hpp"
#include "warehouse/Warehouse.hpp"
#include "warehouse/Bin.hpp"

using namespace wms;
using namespace wms::core;

void printMenu() {
    std::cout << "\n=== ADVANCED WAREHOUSE MANAGEMENT SYSTEM ===\n"
              << " 1. Receive Stock\n"
              << " 2. Create & Validate Order\n"
              << " 3. Pick Order (Generate PickList)\n"
              << " 4. Dispatch Shipment\n"
              << " 5. Record Stock Movement\n"
              << " 6. Trigger Replenishment\n"
              << " 7. Check Inventory On Hand\n"
              << " 8. Check Bin Capacity\n"
              << " 9. Run Cycle Count\n"
              << "10. Generate Discrepancy Report\n"
              << "11. Create Purchase Order\n"
              << "12. Print Price List\n"
              << "13. Assign Employee to Shift\n"
              << "14. Employee Patrol (Security)\n"
              << "15. Generate Utilization Report\n"
              << " 0. Exit\n"
              << "> ";
}

int main() {
    Inventory inventory;
    WarehouseLayout layout("Main Layout");
    Warehouse warehouse("Central WMS", Address("1 Main St", "Berlin", "10115", "Germany"), layout);
    ReportService reportService;
    NotificationService notifier;

    ProductCategory cat("Electronics");
    Product laptop(SKU("ELE-1234"), "Laptop", Money(100000), cat);
    Lot lot("LOT-001");
    Batch batch(lot, std::chrono::system_clock::now() + std::chrono::hours(24));
    
    Order currentOrder("ORD-001");
    PickList currentPickList;
    CycleCount lastCycleCount("Zone-A");
    Picker mainPicker("E-01", "Alice");

    int choice = -1;
    while (choice != 0) {
        printMenu();
        if (!(std::cin >> choice)) break;

        try {
            switch (choice) {
                case 1: {
                    std::cout << "Enter qty: "; int qty; std::cin >> qty;
                    inventory.receive(std::make_shared<StockItem>(laptop, batch, Quantity(qty)));
                    std::cout << "[SUCCESS] Received " << qty << " units.\n";
                    break;
                }
                case 2: {
                    std::cout << "Enter qty: "; int qty; std::cin >> qty;
                    currentOrder = Order("ORD-002");
                    currentOrder.addLine(OrderLine(laptop, Quantity(qty)));
                    OrderService orderService(inventory);
                    orderService.validateOrder(currentOrder);
                    currentOrder.markValidated();
                    std::cout << "[SUCCESS] Order Validated. Total: " << currentOrder.total().cents() / 100.0 << " EUR\n";
                    break;
                }
                case 3: {
                    currentPickList = PickList();
                    currentPickList.addTask(PickTask("BIN-01", laptop.sku(), Quantity(2)));
                    mainPicker.recordPick();
                    std::cout << "[SUCCESS] PickList generated. Alice picked " << mainPicker.itemsPicked() << " items.\n";
                    break;
                }
                case 4: {
                    Carrier carrier("DHL");
                    DeliveryRoute route("Berlin Hub");
                    Shipment shipment(carrier, route);
                    shipment.dispatch();
                    notifier.sendAlert("Shipment dispatched");
                    std::cout << "[SUCCESS] Shipment dispatched via DHL.\n";
                    break;
                }
                case 5: {
                    StockMovement move(laptop.sku(), Quantity(5), "Damaged");
                    std::cout << "[SUCCESS] Logged StockMovement.\n";
                    break;
                }
                case 6: {
                    ReplenishmentTask task(laptop.sku(), Quantity(10));
                    std::cout << "[SUCCESS] Replenishment task created.\n";
                    break;
                }
                case 7: {
                    std::cout << "On Hand: " << inventory.onHand(laptop.sku()).units() 
                              << " | Available: " << inventory.available(laptop.sku()).units() << "\n";
                    break;
                }
                case 8: {
                    Bin bin("BIN-01", CapacityPolicy(Quantity(100)));
                    bin.addStock(Quantity(40));
                    std::cout << "[SUCCESS] Bin space left: " << bin.availableSpace().units() << "\n";
                    break;
                }
                case 9: {
                    lastCycleCount = CycleCount("Zone-A");
                    lastCycleCount.recordCount(laptop.sku());
                    std::cout << "[SUCCESS] Cycle count recorded.\n";
                    break;
                }
                case 10: {
                    DiscrepancyReport report(lastCycleCount, "Missing 2 units");
                    std::cout << "[SUCCESS] Discrepancy Report generated.\n";
                    break;
                }
                case 11: {
                    Address supAddr("Supplier St", "Berlin", "10115", "Germany");
                    Contact supContact("sales@tech.com", "+49123456");
                    Supplier supplier("Tech Corp", supAddr, supContact);
                    PurchaseOrder po(supplier);
                    po.addLine(PurchaseOrderLine(laptop, Quantity(5)));
                    std::cout << "[SUCCESS] PO Created. Total: " << po.total().cents() / 100.0 << " EUR\n";
                    break;
                }
                case 12: {
                    PriceList list;
                    list.addProduct(laptop);
                    std::cout << "[REPORT] PriceList Total: " << list.calculateTotal().cents() / 100.0 << " EUR\n";
                    break;
                }
                case 13: {
                    WarehouseManager mgr("M-01", "Bob");
                    Shift shift(DateRange(std::chrono::system_clock::now(), std::chrono::system_clock::now() + std::chrono::hours(8)));
                    ShiftSchedule schedule;
                    schedule.addShift(shift);
                    std::cout << "[SUCCESS] Shift scheduled for Bob.\n";
                    break;
                }
                case 14: {
                    SecurityGuard guard("S-01", "Charlie");
                    guard.patrol();
                    std::cout << "[SUCCESS] Patrol executed.\n";
                    break;
                }
                case 15: {
                    UtilizationReport report = reportService.generateUtilizationReport(75.5);
                    std::cout << "[REPORT] Utilization: " << report.percent() << "%\n";
                    break;
                }
                case 0: std::cout << "Exiting...\n"; break;
                default: std::cout << "Invalid option.\n";
            }
        } catch (const WarehouseException& ex) {
            std::cerr << "[ERROR] " << ex.what() << "\n";
        }
    }
    return 0;
}
