
#ifndef ORDER_H
#define ORDER_H

#include <string>

class Student;
class DeaneryService;

class Order {
private:
    int orderId;
    Student* student;
    DeaneryService* deaneryService;
    std::string status;

public:
    // Constructor
    Order(
        int orderId,
        Student* student,
        DeaneryService* deaneryService,
        const std::string& status
    );

    // Get order ID
    int getOrderId() const;

    // Get status
    std::string getStatus() const;

    // Update status
    void setStatus(const std::string& status);
};

#endif
