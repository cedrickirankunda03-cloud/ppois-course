
#ifndef ENROLLMENT_H
#define ENROLLMENT_H

#include <string>

class Enrollment {
private:
    int enrollmentId;
    int studentId;
    int courseId;
    std::string enrollmentDate;
    std::string status;

public:
    Enrollment(
        int enrollmentId,
        int studentId,
        int courseId,
        const std::string& enrollmentDate
    );

    int getEnrollmentId() const;
    int getStudentId() const;
    int getCourseId() const;
    std::string getEnrollmentDate() const;
    std::string getStatus() const;

    void setStatus(const std::string& status);

    bool isActive() const;
};

#endif
