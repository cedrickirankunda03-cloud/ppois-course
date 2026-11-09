#include "students/Student.h"
#include <iostream>
#include <stdexcept>

Student::Student(const std::string& id,
                 const std::string& first,
                 const std::string& last,
                 int year)
    : studentId(id),
      firstName(first),
      lastName(last),
      yearOfStudy(year) {

    if (id.empty() || first.empty() || last.empty()) {
        throw std::invalid_argument("Student information cannot be empty.");
    }

    if (year < 1 || year > 6) {
        throw std::invalid_argument("Invalid year of study.");
    }
}

std::string Student::getStudentId() const {
    return studentId;
}

std::string Student::getFirstName() const {
    return firstName;
}

std::string Student::getLastName() const {
    return lastName;
}

int Student::getYearOfStudy() const {
    return yearOfStudy;
}

void Student::updateName(const std::string& first,
                         const std::string& last) {
    if (first.empty() || last.empty()) {
        throw std::invalid_argument("Name cannot be empty.");
    }

    firstName = first;
    lastName = last;
}

void Student::promoteToNextYear() {
    if (yearOfStudy < 6) {
        ++yearOfStudy;
    }
}

void Student::displayInformation() const {
    std::cout << "Student ID: " << studentId << '\n';
    std::cout << "Name: " << firstName << " " << lastName << '\n';
    std::cout << "Year: " << yearOfStudy << '\n';
}
