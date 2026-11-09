#ifndef COURSE_H
#define COURSE_H

#include <string>

class Department;
class Faculty;
class Lecturer;


class Course {
private:
    std::string code;
    std::string name;
    std::string description;
    int credits;

    Faculty* faculty = nullptr;
    Department* department = nullptr;
    Lecturer* lecturer = nullptr;
public:
    Course(
        const std::string& code,
        const std::string& name,
        const std::string& description,
        int credits
    );

    std::string getCode() const;
    std::string getName() const;
    std::string getDescription() const;
    int getCredits() const;

    void setName(const std::string& name);
    void setDescription(const std::string& description);
    void setCredits(int credits);
};

#endif
