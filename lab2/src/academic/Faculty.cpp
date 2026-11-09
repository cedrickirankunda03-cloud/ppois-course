#include "academic/Faculty.h"
#include <algorithm>
#include <stdexcept>

Faculty::Faculty(const std::string& id, const std::string& name)
    : id(id), name(name) {

    if (id.empty() || name.empty()) {
        throw std::invalid_argument(
            "Faculty ID and name cannot be empty"
        );
    }
}

std::string Faculty::getId() const {
    return id;
}

std::string Faculty::getName() const {
    return name;
}

void Faculty::setName(const std::string& name) {
    if (name.empty()) {
        throw std::invalid_argument("Faculty name cannot be empty");
    }

    this->name = name;
}

void Faculty::addDepartment(const std::string& department) {
    if (department.empty()) {
        throw std::invalid_argument("Department cannot be empty");
    }

    if (!hasDepartment(department)) {
        departments.push_back(department);
    }
}

bool Faculty::removeDepartment(const std::string& department) {
    auto it = std::find(
        departments.begin(), departments.end(), department
    );

    if (it == departments.end()) {
        return false;
    }

    departments.erase(it);
    return true;
}

bool Faculty::hasDepartment(const std::string& department) const {
    return std::find(
        departments.begin(), departments.end(), department
    ) != departments.end();
}

int Faculty::getDepartmentCount() const {
    return static_cast<int>(departments.size());
}