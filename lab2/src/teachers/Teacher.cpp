
#include "teachers/Teacher.h"
#include <iostream>
#include <stdexcept>

Teacher::Teacher(
    const std::string& id,
    const std::string& first,
    const std::string& last,
    const std::string& department,
    const std::string& specialization,
    double salary
)
    : teacherId(id),
      firstName(first),
      lastName(last),
      department(department),
      specialization(specialization),
      salary(salary)
{
    if (id.empty() || first.empty() || last.empty() ||
        department.empty() || specialization.empty()) {
        throw std::invalid_argument(
            "Teacher information cannot be empty."
        );
    }

    if (salary < 0) {
        throw std::invalid_argument(
            "Salary cannot be negative."
        );
    }
}

std::string Teacher::getTeacherId() const {
    return teacherId;
}

std::string Teacher::getFullName() const {
    return firstName + " " + lastName;
}

std::string Teacher::getDepartment() const {
    return department;
}

double Teacher::getSalary() const {
    return salary;
}

void Teacher::updateDepartment(
    const std::string& newDepartment
) {
    if (newDepartment.empty()) {
        throw std::invalid_argument(
            "Department cannot be empty."
        );
    }

    department = newDepartment;
}

void Teacher::updateSalary(double newSalary) {
    if (newSalary < 0) {
        throw std::invalid_argument(
            "Salary cannot be negative."
        );
    }

    salary = newSalary;
}

void Teacher::displayInformation() const {
    std::cout << "Teacher ID: " << teacherId << '\n';
    std::cout << "Name: " << getFullName() << '\n';
    std::cout << "Department: " << department << '\n';
    std::cout << "Specialization: " << specialization << '\n';
    std::cout << "Salary: " << salary << '\n';
}

