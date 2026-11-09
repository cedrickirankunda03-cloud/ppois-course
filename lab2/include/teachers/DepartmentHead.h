
#ifndef DEPARTMENT_HEAD_H
#define DEPARTMENT_HEAD_H

#include "Teacher.h"
#include <string>

class Department;


class DepartmentHead : public Teacher {
private:
    int yearsAsHead;
    int teachersSupervised;
    std::string officeNumber;

    Department* managedDepartment = nullptr;
public:
    DepartmentHead(
        const std::string& id,
        const std::string& first,
        const std::string& last,
        const std::string& department,
        const std::string& specialization,
        double salary,
        int years,
        int teachers,
        const std::string& office
    );

    int getYearsAsHead() const;
    int getTeachersSupervised() const;
    std::string getOfficeNumber() const;

    void updateOfficeNumber(const std::string& office);
    void displayDepartmentHeadInformation() const;
};

#endif
