#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>
#include <vector>

class DepartmentHead;
class Faculty;


class Department {
private:
    std::string id;
    std::string name;
    std::string description;
    std::vector<std::string> courses;

    Faculty* faculty = nullptr;
    DepartmentHead* head = nullptr;
public:
    Department(
        const std::string& id,
        const std::string& name,
        const std::string& description
    );

    std::string getId() const;
    std::string getName() const;
    std::string getDescription() const;

    void setName(const std::string& name);
    void setDescription(const std::string& description);

    void addCourse(const std::string& course);
    bool removeCourse(const std::string& course);
    bool hasCourse(const std::string& course) const;

    int getCourseCount() const;
};

#endif
