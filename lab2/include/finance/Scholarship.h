#ifndef SCHOLARSHIP_H
#define SCHOLARSHIP_H

#include <string>

class Scholarship {
private:
    std::string scholarshipId;
    std::string studentId;
    double amount;
    std::string academicYear;

public:
    Scholarship(
        const std::string& scholarshipId,
        const std::string& studentId,
        double amount,
        const std::string& academicYear
    );

    bool isValid() const;
    double getAmount() const;
    std::string getScholarshipId() const;
};

#endif