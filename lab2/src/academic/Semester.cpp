#include "academic/Semester.h"
#include <stdexcept>

Semester::Semester(
    const std::string& id,
    const std::string& name,
    const std::string& startDate,
    const std::string& endDate
) : id(id),
    name(name),
    startDate(startDate),
    endDate(endDate),
    active(false) {

    if (id.empty() || name.empty() ||
        startDate.empty() || endDate.empty()) {
        throw std::invalid_argument(
            "Semester information cannot be empty"
        );
    }

    if (startDate > endDate) {
        throw std::invalid_argument(
            "Start date cannot be after end date"
        );
    }
}

std::string Semester::getId() const {
    return id;
}

std::string Semester::getName() const {
    return name;
}

std::string Semester::getStartDate() const {
    return startDate;
}

std::string Semester::getEndDate() const {
    return endDate;
}

bool Semester::isActive() const {
    return active;
}

void Semester::setName(const std::string& name) {
    if (name.empty()) {
        throw std::invalid_argument("Name cannot be empty");
    }

    this->name = name;
}

void Semester::setDates(
    const std::string& startDate,
    const std::string& endDate
) {
    if (startDate.empty() || endDate.empty() ||
        startDate > endDate) {
        throw std::invalid_argument("Invalid semester dates");
    }

    this->startDate = startDate;
    this->endDate = endDate;
}

void Semester::activate() {
    active = true;
}

void Semester::deactivate() {
    active = false;
}
