
#ifndef STUDENT_GROUP_H
#define STUDENT_GROUP_H

#include <string>
#include <vector>

class Student;

class StudentGroup {
private:
    int groupId;
    std::string groupName;
    std::vector<Student*> students;

public:
    StudentGroup(int groupId, const std::string& groupName);

    int getGroupId() const;
    std::string getGroupName() const;

    void addStudent(Student* student);
    void removeStudent(Student* student);

    int getStudentCount() const;
};

#endif
