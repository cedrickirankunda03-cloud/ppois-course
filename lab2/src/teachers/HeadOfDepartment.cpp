
#include "teachers/HeadOfDepartment.h"
#include <iostream>

using namespace std;

HeadOfDepartment::HeadOfDepartment(
    const string& id,
    const string& department,
    const string& teacher
)
    : headId(id),
      departmentId(department),
      teacherId(teacher)
{
}

string HeadOfDepartment::getHeadId() const {
    return headId;
}

string HeadOfDepartment::getDepartmentId() const {
    return departmentId;
}

string HeadOfDepartment::getTeacherId() const {
    return teacherId;
}

void HeadOfDepartment::displayInformation() const {
    cout << "\n===== HEAD OF DEPARTMENT =====" << endl;
    cout << "Head ID: " << headId << endl;
    cout << "Department ID: " << departmentId << endl;
    cout << "Teacher ID: " << teacherId << endl;
}

