#ifndef TEACHER_H
#define TEACHER_H

#include <string>

class Department;
class TeacherSchedule;


class Teacher {
private:
    std::string teacherId;
    std::string firstName;
    std::string lastName;
    std::string department;
    std::string specialization;
    double salary;

    Department* departmentRef = nullptr;
    TeacherSchedule* schedule = nullptr;
public:
    Teacher(
        const std::string& id,
        const std::string& first,
        const std::string& last,
        const std::string& department,
        const std::string& specialization,
        double salary
    );

    std::string getTeacherId() const;
    std::string getFullName() const;
    std::string getDepartment() const;
    double getSalary() const;

    void updateDepartment(const std::string& newDepartment);
    void updateSalary(double newSalary);

    void displayInformation() const;
};

#endif
