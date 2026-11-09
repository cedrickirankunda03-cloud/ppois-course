#ifndef UNDERGRADUATE_STUDENT_H
#define UNDERGRADUATE_STUDENT_H

#include "Student.h"
#include <string>

class Enrollment;


class UndergraduateStudent : public Student {
private:
    std::string specialization;
    int creditsCompleted;
    bool internshipRegistered;

    Enrollment* enrollment = nullptr;
public:
    UndergraduateStudent(
        const std::string& id,
        const std::string& first,
        const std::string& last,
        int year,
        const std::string& specialization,
        int credits
    );

    std::string getSpecialization() const;
    int getCreditsCompleted() const;

    void completeCredits(int credits);
    bool isEligibleForInternship() const;
    bool registerForInternship();

    void displayInformation() const override;
};

#endif
