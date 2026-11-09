#include "finance/Finance.h"

#include <stdexcept>
#include <cmath>

// Constructor
Finance::Finance(const std::string& financeId,
                 double annualBudget)
    : financeId(financeId),
      annualBudget(annualBudget),
      totalPayments(0.0),
      totalScholarships(0.0)
{
    if (financeId.empty() ||
        !std::isfinite(annualBudget) ||
        annualBudget < 0)
    {
        throw std::invalid_argument(
            "Invalid finance information"
        );
    }
}

// Getters
std::string Finance::getFinanceId() const
{
    return financeId;
}

double Finance::getAnnualBudget() const
{
    return annualBudget;
}

double Finance::getTotalPayments() const
{
    return totalPayments;
}

double Finance::getTotalScholarships() const
{
    return totalScholarships;
}

// Record payment
void Finance::recordPayment(double amount)
{
    if (!std::isfinite(amount) || amount < 0)
    {
        throw std::invalid_argument(
            "Invalid payment amount"
        );
    }

    totalPayments += amount;
}

// Record scholarship
void Finance::recordScholarship(double amount)
{
    if (!std::isfinite(amount) || amount < 0)
    {
        throw std::invalid_argument(
            "Invalid scholarship amount"
        );
    }

    totalScholarships += amount;
}

// Calculate remaining budget
double Finance::getRemainingBudget() const
{
    return annualBudget -
           totalPayments -
           totalScholarships;
}