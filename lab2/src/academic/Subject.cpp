#include "academic/Subject.h"

#include <stdexcept>

Subject::Subject(
    const std::string& name,
    const std::string& description,
    int credits
) {
    setName(name);
    setDescription(description);
    setCredits(credits);
}

std::string Subject::getName() const {
    return name;
}

std::string Subject::getDescription() const {
    return description;
}

int Subject::getCredits() const {
    return credits;
}

void Subject::setName(const std::string& name) {
    if (name.empty()) {
        throw std::invalid_argument("Subject name cannot be empty");
    }

    this->name = name;
}

void Subject::setDescription(const std::string& description) {
    this->description = description;
}

void Subject::setCredits(int credits) {
    if (credits <= 0) {
        throw std::invalid_argument("Credits must be positive");
    }

    this->credits = credits;
}