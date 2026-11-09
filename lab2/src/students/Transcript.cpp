#include "students/Transcript.h"

#include <stdexcept>

Transcript::Transcript(
    Student* student,
    const std::string& academicYear
) : student(student), academicYear(academicYear) {

    if (student == nullptr) {
        throw std::invalid_argument("Student cannot be null");
    }

    if (academicYear.empty()) {
        throw std::invalid_argument("Academic year cannot be empty");
    }
}

void Transcript::setStudent(Student* student) {
    if (student == nullptr) {
        throw std::invalid_argument("Student cannot be null");
    }

    this->student = student;
}

void Transcript::addGrade(const Grade& grade) {
    grades.push_back(grade);
}

const std::vector<Grade>& Transcript::getGrades() const {
    return grades;
}

std::string Transcript::getAcademicYear() const {
    return academicYear;
}
