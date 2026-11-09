#ifndef ACADEMIC_H
#define ACADEMIC_H

#include <string>
#include <vector>

class Academic {
private:
    std::string academicYear;
    std::vector<std::string> departments;

public:
    // Constructor
    explicit Academic(const std::string& academicYear);

    // Get academic year
    std::string getAcademicYear() const;

    // Change academic year
    void setAcademicYear(const std::string& academicYear);

    // Department management
    void addDepartment(const std::string& department);
    bool removeDepartment(const std::string& department);
    int getDepartmentCount() const;
};

#endif