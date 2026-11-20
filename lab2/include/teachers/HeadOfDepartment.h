
#ifndef HEAD_OF_DEPARTMENT_H
#define HEAD_OF_DEPARTMENT_H

#include <string>

class HeadOfDepartment {
private:
    std::string headId;
    std::string departmentId;
    std::string teacherId;

public:
    HeadOfDepartment(
        const std::string& id,
        const std::string& department,
        const std::string& teacher
    );

    const std::string& getHeadId() const;
    const std::string& getDepartmentId() const;
    const std::string& getTeacherId() const;

    void displayInformation() const;
};

#endif
