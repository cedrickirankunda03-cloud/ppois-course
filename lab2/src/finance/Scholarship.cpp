#include "finance/Scholarship.h"

#include <cmath>
#include <stdexcept>

Scholarship::Scholarship(
    const std::string& scholarshipId,
    const std::string& studentId,
    double amount,
    const std::string& academicYear
)
    : scholarshipId(scholarshipId),
      studentId(studentId),
      amount(amount),
      academicYear(academicYear)
{
    if (scholarshipId.empty() ||
        studentId.empty() ||
        academicYear.empty() ||
        !std::isfinite(amount) ||
        amount <= 0)
    {
        throw std::invalid_argument(
            "Invalid scholarship information"
        );
    }
}

bool Scholarship::isValid() const
{
    return !scholarshipId.empty() &&
           !studentId.empty() &&
           !academicYear.empty() &&
           std::isfinite(amount) &&
           amount > 0;
}

double Scholarship::getAmount() const
{
    return amount;
}

std::string Scholarship::getScholarshipId() const
{
    return scholarshipId;
}