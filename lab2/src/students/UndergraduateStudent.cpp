#include "students/UndergraduateStudent.h"
#include <iostream>
#include <stdexcept>

UndergraduateStudent::UndergraduateStudent(
    const std::string& id,
    const std::string& first,
    const std::string& last,
    int year,
    const std::string& specialization,
    int credits
)
    : Student(id, first, last, year),
      specialization(specialization),
      creditsCompleted(credits),
      internshipRegistered(false) {

    if (specialization.empty()) {
        throw std::invalid_argument("Specialization cannot be empty.");
    }

    if (credits < 0) {
        throw std::invalid_argument("Credits cannot be negative.");
    }
}

std::string UndergraduateStudent::getSpecialization() const {
    return specialization;
}

int UndergraduateStudent::getCreditsCompleted() const {
    return creditsCompleted;
}

void UndergraduateStudent::completeCredits(int credits) {
    if (credits <= 0) {
        throw std::invalid_argument("Credits must be positive.");
    }

    creditsCompleted += credits;
}

bool UndergraduateStudent::isEligibleForInternship() const {
    return creditsCompleted >= 60;
}

bool UndergraduateStudent::registerForInternship() {
    if (!isEligibleForInternship() || internshipRegistered) {
        return false;
    }

    internshipRegistered = true;
    return true;
}

void UndergraduateStudent::displayInformation() const {
    Student::displayInformation();

    std::cout << "Specialization: " << specialization << '\n';
    std::cout << "Credits completed: " << creditsCompleted << '\n';
    std::cout << "Internship registered: "
              << (internshipRegistered ? "Yes" : "No") << '\n';
}
