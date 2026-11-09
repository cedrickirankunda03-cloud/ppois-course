
#include "services/ScholarshipManager.h"

#include <algorithm>
#include <stdexcept>

// Constructor
ScholarshipAwardService::ScholarshipAwardService(
    double maximumScholarship)
    : maximumScholarship(maximumScholarship),
      scholarshipsAwarded(0)
{
    if (maximumScholarship <= 0)
    {
        throw std::invalid_argument(
            "Maximum scholarship must be positive.");
    }
}

// Award a scholarship
void ScholarshipAwardService::awardScholarship(
    const std::string& scholarshipId)
{
    if (scholarshipId.empty())
    {
        throw std::invalid_argument(
            "Scholarship ID cannot be empty.");
    }

    if (hasScholarship(scholarshipId))
    {
        throw std::invalid_argument(
            "Scholarship has already been awarded.");
    }

    scholarshipIds.push_back(scholarshipId);
    ++scholarshipsAwarded;
}

// Revoke a scholarship
void ScholarshipAwardService::revokeScholarship(
    const std::string& scholarshipId)
{
    auto it = std::find(
        scholarshipIds.begin(),
        scholarshipIds.end(),
        scholarshipId
    );

    if (it == scholarshipIds.end())
    {
        throw std::invalid_argument(
            "Scholarship not found.");
    }

    scholarshipIds.erase(it);
    --scholarshipsAwarded;
}

// Check whether a scholarship was awarded
bool ScholarshipAwardService::hasScholarship(
    const std::string& scholarshipId) const
{
    return std::find(
        scholarshipIds.begin(),
        scholarshipIds.end(),
        scholarshipId
    ) != scholarshipIds.end();
}

// Get the number of awarded scholarships
int ScholarshipAwardService::getScholarshipsAwarded() const
{
    return scholarshipsAwarded;
}

// Get the maximum scholarship amount
double ScholarshipAwardService::getMaximumScholarship() const
{
    return maximumScholarship;
}
