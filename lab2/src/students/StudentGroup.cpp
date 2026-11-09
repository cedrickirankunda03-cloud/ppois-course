
#include "students/StudentGroup.h"
#include "students/Student.h"

#include <algorithm>
#include <stdexcept>

StudentGroup::StudentGroup(
    int groupId,
    const std::string& groupName
) : groupId(groupId), groupName(groupName) {

    if (groupId <= 0) {
        throw std::invalid_argument("Group ID must be positive.");
    }

    if (groupName.empty()) {
        throw std::invalid_argument("Group name cannot be empty.");
    }
}

int StudentGroup::getGroupId() const {
    return groupId;
}

std::string StudentGroup::getGroupName() const {
    return groupName;
}

void StudentGroup::addStudent(Student* student) {
    if (student == nullptr) {
        throw std::invalid_argument("Student cannot be null.");
    }

    if (std::find(students.begin(), students.end(), student)
        != students.end()) {
        throw std::invalid_argument("Student already exists in group.");
    }

    students.push_back(student);
}

void StudentGroup::removeStudent(Student* student) {
    auto it = std::find(students.begin(), students.end(), student);

    if (it != students.end()) {
        students.erase(it);
    }
}

int StudentGroup::getStudentCount() const {
    return static_cast<int>(students.size());
}
