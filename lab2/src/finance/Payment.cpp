#include "finance/Payment.h"

#include <stdexcept>
#include <cmath>
#include <sstream>
#include <iomanip>

Payment::Payment(
    const std::string& paymentId,
    const std::string& contractId,
    const std::string& studentId,
    double amount)
    : paymentId(paymentId),
      contractId(contractId),
      studentId(studentId),
      amount(amount)
{
    if (paymentId.empty() ||
        contractId.empty() ||
        studentId.empty() ||
        !std::isfinite(amount) ||
        amount < 0)
    {
        throw std::invalid_argument(
            "Invalid payment information"
        );
    }
}

std::string Payment::getPaymentId() const
{
    return paymentId;
}

std::string Payment::getContractId() const
{
    return contractId;
}

std::string Payment::getStudentId() const
{
    return studentId;
}

double Payment::getAmount() const
{
    return amount;
}

void Payment::updateAmount(double amount)
{
    if (!std::isfinite(amount) || amount < 0)
    {
        throw std::invalid_argument(
            "Invalid payment amount"
        );
    }

    this->amount = amount;
}

bool Payment::isValid() const
{
    return !paymentId.empty() &&
           !contractId.empty() &&
           !studentId.empty() &&
           std::isfinite(amount) &&
           amount >= 0;
}

std::string Payment::generateReceipt() const
{
    std::ostringstream receipt;

    receipt << std::fixed << std::setprecision(2);

    receipt << "========== PAYMENT RECEIPT ==========\n";
    receipt << "Payment ID: " << paymentId << "\n";
    receipt << "Contract ID: " << contractId << "\n";
    receipt << "Student ID: " << studentId << "\n";
    receipt << "Amount: " << amount << "\n";
    receipt << "=====================================";

    return receipt.str();
}