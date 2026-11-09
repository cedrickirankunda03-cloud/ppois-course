#ifndef FINANCE_SCHOLARSHIP_MANAGER_H
#define FINANCE_SCHOLARSHIP_MANAGER_H

#include <string>
#include <vector>
#include <cstddef>

#include "finance/Scholarship.h"

class ScholarshipManager {
private:
    std::string managerId;
    std::vector<Scholarship> scholarships;
    double maximumScholarship;

public:
    ScholarshipManager(
        const std::string& managerId,
        double maximumScholarship
    );

    std::string getManagerId() const;
    double getMaximumScholarship() const;

    void addScholarship(const Scholarship& scholarship);
    bool removeScholarship(const std::string& scholarshipId);

    Scholarship* findScholarship(
        const std::string& scholarshipId
    );

    double calculateTotalScholarships() const;
    std::size_t getScholarshipCount() const;
};

#endif