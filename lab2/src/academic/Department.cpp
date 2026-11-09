#include "academic/Department.h"
#include <algorithm>
#include <stdexcept>

Department::Department(
    const std::string& id,
    const std::string& name,
    const std::string& description
) : id(id), name(name), description(description) {

    if (id.empty() || name.empty()) {
        throw std::invalid_argument(
            "Department ID and name cannot be empty"
        );
    }
}

std::string Department::getId() const {
    return id;
}

std::string Department::getName() const {
    return name;
}

std::string Department::getDescription() const {
    return description;
}

void Department::setName(const std::string& name) {
    if (name.empty()) {
        throw std::invalid_argument(
            "Department name cannot be empty"
        );
    }

    this->name = name;
}

void Department::setDescription(const std::string& description) {
    this->description = description;
}

void Department::addCourse(const std::string& course) {
    if (course.empty()) {
        throw std::invalid_argument(
            "Course cannot be empty"
        );
    }

    if (!hasCourse(course)) {
        courses.push_back(course);
    }
}

bool Department::removeCourse(const std::string& course) {
    auto it = std::find(
        courses.begin(), courses.end(), course
    );

    if (it == courses.end()) {
        return false;
    }

    courses.erase(it);
    return true;
}

bool Department::hasCourse(const std::string& course) const {
    return std::find(
        courses.begin(), courses.end(), course
    ) != courses.end();
}

int Department::getCourseCount() const {
    return static_cast<int>(courses.size());
}