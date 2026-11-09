
#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>

class Student;
class Order;

class Application {
private:
    int applicationId;
    Student* student;
    Order* order;
    std::string status;

public:
    // Constructor
    Application(
        int applicationId,
        Student* student,
        Order* order,
        const std::string& status
    );

    // Get application ID
    int getApplicationId() const;

    // Get application status
    std::string getStatus() const;

    // Update application status
    void setStatus(const std::string& status);
};

#endif
