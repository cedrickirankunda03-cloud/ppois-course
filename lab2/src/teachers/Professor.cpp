#include "teachers/Professor.h"
#include <iostream>
#include <stdexcept>

Professor::Professor(
    const std::string& id,
    const std::string& first,
    const std::string& last,
    const std::string& department,
    const std::string& specialization,
    double salary,
    const std::string& rank,
    const std::string& research,
    int experience,
    int publications
)
    : Teacher(id, first, last, department, specialization, salary),
      academicRank(rank),
      researchField(research),
      yearsOfExperience(experience),
      publications(publications)
{
    if (rank.empty() || research.empty()) {
        throw std::invalid_argument(
            "Academic rank and research field cannot be empty."
        );
    }

    if (experience < 0 || publications < 0) {
        throw std::invalid_argument(
            "Experience and publications cannot be negative."
        );
    }
}

std::string Professor::getAcademicRank() const {
    return academicRank;
}

std::string Professor::getResearchField() const {
    return researchField;
}

int Professor::getPublications() const {
    return publications;
}

void Professor::addPublication() {
    ++publications;
}

void Professor::updateAcademicRank(const std::string& rank) {
    if (rank.empty()) {
        throw std::invalid_argument(
            "Academic rank cannot be empty."
        );
    }

    academicRank = rank;
}

void Professor::displayProfessorInformation() const {
    displayInformation();

    std::cout << "Academic rank: " << academicRank << '\n';
    std::cout << "Research field: " << researchField << '\n';
    std::cout << "Years of experience: "
              << yearsOfExperience << '\n';
    std::cout << "Publications: " << publications << '\n';
}
