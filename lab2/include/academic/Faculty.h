#ifndef FACULTY_H
#define FACULTY_H

#include <string>
#include <vector>

class Faculty {
private:
    std::string id;
    std::string name;
    std::vector<std::string> departments;

public:
    Faculty(const std::string& id, const std::string& name);

    std::string getId() const;
    std::string getName() const;

    void setName(const std::string& name);

    void addDepartment(const std::string& department);
    bool removeDepartment(const std::string& department);
    bool hasDepartment(const std::string& department) const;

    int getDepartmentCount() const;
};

#endif