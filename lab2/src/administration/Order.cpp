
#include "administration/Order.h"

#include <stdexcept>

Order::Order(
    int orderId,
    Student* student,
    DeaneryService* deaneryService,
    const std::string& status
) : orderId(orderId),
    student(student),
    deaneryService(deaneryService),
    status(status) {

    if (orderId <= 0) {
        throw std::invalid_argument("Invalid order ID");
    }

    if (student == nullptr || deaneryService == nullptr) {
        throw std::invalid_argument("Associated objects cannot be null");
    }

    if (status.empty()) {
        throw std::invalid_argument("Status cannot be empty");
    }
}

int Order::getOrderId() const {
    return orderId;
}

std::string Order::getStatus() const {
    return status;
}

void Order::setStatus(const std::string& status) {
    if (status.empty()) {
        throw std::invalid_argument("Status cannot be empty");
    }

    this->status = status;
}
