#pragma once

#include <string>

class Contract;
class Scholarship;


class Payment
{
private:
    std::string paymentId;
    std::string contractId;
    std::string studentId;
    double amount;

    Contract* contract = nullptr;
    Scholarship* scholarship = nullptr;
public:
    Payment(const std::string& paymentId,
            const std::string& contractId,
            const std::string& studentId,
            double amount);

    const std::string& getPaymentId() const;
    const std::string& getContractId() const;
    const std::string& getStudentId() const;
    double getAmount() const;

    void updateAmount(double amount);
    bool isValid() const;
    std::string generateReceipt() const;
};
