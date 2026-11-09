#include "finance/Contract.h"

#include <stdexcept>
#include <cmath>

Contract::Contract(
    const std::string& contractId,
    const std::string& studentId,
    double totalAmount,
    const std::string& contractDate
)
    : contractId(contractId),
      studentId(studentId),
      totalAmount(totalAmount),
      contractDate(contractDate),
      status("Pending")
{
    if (contractId.empty() ||
        studentId.empty() ||
        contractDate.empty() ||
        !std::isfinite(totalAmount) ||
        totalAmount < 0)
    {
        throw std::invalid_argument(
            "Invalid contract information"
        );
    }
}

std::string Contract::getContractId() const
{
    return contractId;
}

std::string Contract::getStudentId() const
{
    return studentId;
}

double Contract::getTotalAmount() const
{
    return totalAmount;
}

std::string Contract::getContractDate() const
{
    return contractDate;
}

std::string Contract::getStatus() const
{
    return status;
}

void Contract::updateAmount(double amount)
{
    if (!std::isfinite(amount) || amount < 0)
    {
        throw std::invalid_argument(
            "Invalid contract amount"
        );
    }

    if (status != "Pending")
    {
        throw std::logic_error(
            "Only pending contracts can be updated"
        );
    }

    totalAmount = amount;
}

void Contract::signContract()
{
    if (status != "Pending")
    {
        throw std::logic_error(
            "Contract cannot be signed"
        );
    }

    status = "Signed";
}

void Contract::cancelContract()
{
    if (status == "Cancelled")
    {
        throw std::logic_error(
            "Contract is already cancelled"
        );
    }

    status = "Cancelled";
}

bool Contract::isSigned() const
{
    return status == "Signed";
}

bool Contract::isCancelled() const
{
    return status == "Cancelled";
}