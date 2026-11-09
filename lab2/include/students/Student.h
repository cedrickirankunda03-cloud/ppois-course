#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class StudentGroup;
class StudentProfile;
class Transcript;


class Student {
private:
    std::string studentId;
    std::string firstName;
    std::string lastName;
    int yearOfStudy;

    StudentProfile* profile = nullptr;
    Transcript* transcript = nullptr;
    StudentGroup* group = nullptr;
public:
    // Constructor
    Student(const std::string& id,
            const std::string& first,
            const std::string& last,
            int year);

    virtual ~Student() = default;

    // Getters
    std::string getStudentId() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    int getYearOfStudy() const;

    // Student behaviours
    void updateName(const std::string& first,
                    const std::string& last);

    void promoteToNextYear();

    virtual void displayInformation() const;
};

#endif
