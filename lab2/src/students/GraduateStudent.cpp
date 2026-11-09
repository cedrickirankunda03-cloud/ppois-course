#include "students/GraduateStudent.h"
#include <iostream>
#include <stdexcept>

GraduateStudent::GraduateStudent(
    const std::string& id,
    const std::string& first,
    const std::string& last,
    int year,
    const std::string& research,
    const std::string& thesis,
    const std::string& supervisor
)
    : Student(id, first, last, year),
      researchArea(research),
      thesisTitle(thesis),
      supervisorName(supervisor),
      researchProgress(0),
      thesisSubmitted(false) {

    if (researchArea.empty() ||
        thesisTitle.empty() ||
        supervisorName.empty()) {
        throw std::invalid_argument(
            "Research information cannot be empty."
        );
    }
}

std::string GraduateStudent::getResearchArea() const {
    return researchArea;
}

std::string GraduateStudent::getThesisTitle() const {
    return thesisTitle;
}

int GraduateStudent::getResearchProgress() const {
    return researchProgress;
}

void GraduateStudent::updateResearchProgress(int progress) {
    if (progress < 0 || progress > 100) {
        throw std::invalid_argument(
            "Research progress must be between 0 and 100."
        );
    }

    if (thesisSubmitted) {
        throw std::logic_error(
            "Cannot update a submitted thesis."
        );
    }

    researchProgress = progress;
}

void GraduateStudent::changeThesisTitle(
    const std::string& newTitle) {

    if (newTitle.empty()) {
        throw std::invalid_argument(
            "Thesis title cannot be empty."
        );
    }

    if (thesisSubmitted) {
        throw std::logic_error(
            "Cannot change a submitted thesis."
        );
    }

    thesisTitle = newTitle;
}

void GraduateStudent::submitThesis() {
    if (researchProgress < 100) {
        throw std::logic_error(
            "Complete your research before submitting."
        );
    }

    thesisSubmitted = true;
}

bool GraduateStudent::isThesisSubmitted() const {
    return thesisSubmitted;
}

void GraduateStudent::displayInformation() const {
    Student::displayInformation();

    std::cout << "Research area: " << researchArea << '\n';
    std::cout << "Thesis title: " << thesisTitle << '\n';
    std::cout << "Supervisor: " << supervisorName << '\n';
    std::cout << "Research progress: "
              << researchProgress << "%\n";
    std::cout << "Thesis submitted: "
              << (thesisSubmitted ? "Yes" : "No") << '\n';
}
