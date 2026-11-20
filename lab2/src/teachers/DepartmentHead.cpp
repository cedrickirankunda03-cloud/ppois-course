
#include "teachers/DepartmentHead.h"
#include <iostream>

using namespace std;

// Constructor
DepartmentHead::DepartmentHead(
    const std::string& id,
    const std::string& first,
    const std::string& last,
    const std::string& department,
    const std::string& specialization,
    double salary,
    int years,
    int teachers,
    const std::string& office
)
    : Teacher(id, first, last, department, specialization, salary),
      yearsAsHead(years),
      teachersSupervised(teachers),
      officeNumber(office)
{
}

// Getters
int DepartmentHead::getYearsAsHead() const {
    return yearsAsHead;
}

int DepartmentHead::getTeachersSupervised() const {
    return teachersSupervised;
}

const std::string& DepartmentHead::getOfficeNumber() const {
    return officeNumber;
}

// Update office number
void DepartmentHead::updateOfficeNumber(const std::string& office) {
    officeNumber = office;
}

// Display information
void DepartmentHead::displayDepartmentHeadInformation() const {
    cout << "\n===== DEPARTMENT HEAD INFORMATION =====" << endl;

    displayInformation();

    cout << "Years as Department Head: "
         << yearsAsHead << endl;

    cout << "Teachers Supervised: "
         << teachersSupervised << endl;

    cout << "Office Number: "
         << officeNumber << endl;
}

