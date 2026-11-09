#pragma once

#include <string>

class Finance
{
private:
    std::string financeId;
    double annualBudget;
    double totalPayments;
    double totalScholarships;

public:
    // Constructor
    Finance(const std::string& financeId,
            double annualBudget);

    // Getters
    std::string getFinanceId() const;
    double getAnnualBudget() const;
    double getTotalPayments() const;
    double getTotalScholarships() const;

    // Financial operations
    void recordPayment(double amount);
    void recordScholarship(double amount);
    double getRemainingBudget() const;
};