
#ifndef SERVICES_SCHOLARSHIP_AWARD_SERVICE_H
#define SERVICES_SCHOLARSHIP_AWARD_SERVICE_H

#include <string>
#include <vector>

class ScholarshipAwardService
{
private:
    double maximumScholarship;
    int scholarshipsAwarded;
    std::vector<std::string> scholarshipIds;

public:
    explicit ScholarshipAwardService(double maximumScholarship);

    void awardScholarship(const std::string& scholarshipId);
    void revokeScholarship(const std::string& scholarshipId);

    bool hasScholarship(const std::string& scholarshipId) const;

    int getScholarshipsAwarded() const;
    double getMaximumScholarship() const;
};

#endif
