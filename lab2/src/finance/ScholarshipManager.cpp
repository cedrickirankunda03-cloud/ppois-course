
#include "finance/ScholarshipManager.h"

#include <stdexcept>
#include <cmath>

ScholarshipManager::ScholarshipManager(
    const std::string& managerId,
    double maximumScholarship)
    : managerId(managerId),
      maximumScholarship(maximumScholarship)
{
    if (managerId.empty() ||
        !std::isfinite(maximumScholarship) ||
        maximumScholarship < 0)
    {
        throw std::invalid_argument(
            "Invalid scholarship manager information"
        );
    }
}

std::string ScholarshipManager::getManagerId() const
{
    return managerId;
}

double ScholarshipManager::getMaximumScholarship() const
{
    return maximumScholarship;
}

void ScholarshipManager::addScholarship(
    const Scholarship& scholarship)
{
    if (!scholarship.isValid())
    {
        throw std::invalid_argument(
            "Invalid scholarship"
        );
    }

    if (scholarship.getAmount() > maximumScholarship)
    {
        throw std::invalid_argument(
            "Scholarship exceeds maximum limit"
        );
    }

    for (const auto& existing : scholarships)
    {
        if (existing.getScholarshipId() ==
            scholarship.getScholarshipId())
        {
            throw std::invalid_argument(
                "Duplicate scholarship"
            );
        }
    }

    scholarships.push_back(scholarship);
}

bool ScholarshipManager::removeScholarship(
    const std::string& scholarshipId)
{
    for (auto it = scholarships.begin();
         it != scholarships.end(); ++it)
    {
        if (it->getScholarshipId() == scholarshipId)
        {
            scholarships.erase(it);
            return true;
        }
    }

    return false;
}

Scholarship* ScholarshipManager::findScholarship(
    const std::string& scholarshipId)
{
    for (auto& scholarship : scholarships)
    {
        if (scholarship.getScholarshipId() == scholarshipId)
        {
            return &scholarship;
        }
    }

    return nullptr;
}

double ScholarshipManager::calculateTotalScholarships() const
{
    double total = 0.0;

    for (const auto& scholarship : scholarships)
    {
        total += scholarship.getAmount();
    }

    return total;
}

std::size_t ScholarshipManager::getScholarshipCount() const
{
    return scholarships.size();
}
