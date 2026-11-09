#include "academic/Course.h"
#include <stdexcept>

Course::Course(
    const std::string& code,
    const std::string& name,
    const std::string& description,
    int credits
) : code(code),
    name(name),
    description(description),
    credits(credits) {

    if (code.empty() || name.empty()) {
        throw std::invalid_argument(
            "Course code and name cannot be empty"
        );
    }

    if (credits <= 0) {
        throw std::invalid_argument(
            "Credits must be greater than zero"
        );
    }
}

std::string Course::getCode() const {
    return code;
}

std::string Course::getName() const {
    return name;
}

std::string Course::getDescription() const {
    return description;
}

int Course::getCredits() const {
    return credits;
}

void Course::setName(const std::string& name) {
    if (name.empty()) {
        throw std::invalid_argument(
            "Course name cannot be empty"
        );
    }

    this->name = name;
}

void Course::setDescription(const std::string& description) {
    this->description = description;
}

void Course::setCredits(int credits) {
    if (credits <= 0) {
        throw std::invalid_argument(
            "Credits must be greater than zero"
        );
    }

    this->credits = credits;
}