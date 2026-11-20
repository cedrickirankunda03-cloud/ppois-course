
#include "teachers/HeadOfDepartment.h"
#include <iostream>

using namespace std;

HeadOfDepartment::HeadOfDepartment(
    const std::string& id,
    const std::string& department,
    const std::string& teacher
)
    : headId(id),
      departmentId(department),
      teacherId(teacher)
{
}

const std::string& HeadOfDepartment::getHeadId() const {
    return headId;
}

const std::string& HeadOfDepartment::getDepartmentId() const {
    return departmentId;
}

const std::string& HeadOfDepartment::getTeacherId() const {
    return teacherId;
}

void HeadOfDepartment::displayInformation() const {
    cout << "\n===== HEAD OF DEPARTMENT =====" << endl;
    cout << "Head ID: " << headId << endl;
    cout << "Department ID: " << departmentId << endl;
    cout << "Teacher ID: " << teacherId << endl;
}

