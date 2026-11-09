#pragma once

#include <string>

class Payment;
class Student;


class Contract
{
private:
    std::string contractId;
    std::string studentId;
    double totalAmount;
    std::string contractDate;
    std::string status;

    Student* student = nullptr;
    Payment* payment = nullptr;
public:
    Contract(
        const std::string& contractId,
        const std::string& studentId,
        double totalAmount,
        const std::string& contractDate
    );

    std::string getContractId() const;
    std::string getStudentId() const;
    double getTotalAmount() const;
    std::string getContractDate() const;
    std::string getStatus() const;

    void updateAmount(double amount);
    void signContract();
    void cancelContract();

    bool isSigned() const;
    bool isCancelled() const;
};
