#include "academic/Academic.h"

#include <algorithm>
#include <stdexcept>

Academic::Academic(const std::string& academicYear) {
    setAcademicYear(academicYear);
}

std::string Academic::getAcademicYear() const {
    return academicYear;
}

void Academic::setAcademicYear(const std::string& academicYear) {
    if (academicYear.empty()) {
        throw std::invalid_argument("Academic year cannot be empty");
    }

    this->academicYear = academicYear;
}

void Academic::addDepartment(const std::string& department) {
    if (department.empty()) {
        throw std::invalid_argument("Department cannot be empty");
    }

    if (std::find(departments.begin(), departments.end(), department)
        == departments.end()) {
        departments.push_back(department);
    }
}

bool Academic::removeDepartment(const std::string& department) {
    auto it = std::find(
        departments.begin(),
        departments.end(),
        department
    );

    if (it == departments.end()) {
        return false;
    }

    departments.erase(it);
    return true;
}

int Academic::getDepartmentCount() const {
    return static_cast<int>(departments.size());
}