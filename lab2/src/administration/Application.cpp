
#include "administration/Application.h"

#include <stdexcept>

Application::Application(
    int applicationId,
    Student* student,
    Order* order,
    const std::string& status
) : applicationId(applicationId),
    student(student),
    order(order),
    status(status) {

    if (applicationId <= 0) {
        throw std::invalid_argument("Invalid application ID");
    }

    if (student == nullptr || order == nullptr) {
        throw std::invalid_argument("Student and order cannot be null");
    }

    if (status.empty()) {
        throw std::invalid_argument("Status cannot be empty");
    }
}

int Application::getApplicationId() const {
    return applicationId;
}

std::string Application::getStatus() const {
    return status;
}

void Application::setStatus(const std::string& status) {
    if (status.empty()) {
        throw std::invalid_argument("Status cannot be empty");
    }

    this->status = status;
}
