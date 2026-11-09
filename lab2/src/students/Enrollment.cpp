
#include "students/Enrollment.h"

#include <stdexcept>

Enrollment::Enrollment(
    int enrollmentId,
    int studentId,
    int courseId,
    const std::string& enrollmentDate
) : enrollmentId(enrollmentId),
    studentId(studentId),
    courseId(courseId),
    enrollmentDate(enrollmentDate),
    status("Active") {

    if (enrollmentId <= 0 || studentId <= 0 || courseId <= 0) {
        throw std::invalid_argument("IDs must be positive.");
    }

    if (enrollmentDate.empty()) {
        throw std::invalid_argument("Enrollment date cannot be empty.");
    }
}

int Enrollment::getEnrollmentId() const {
    return enrollmentId;
}

int Enrollment::getStudentId() const {
    return studentId;
}

int Enrollment::getCourseId() const {
    return courseId;
}

std::string Enrollment::getEnrollmentDate() const {
    return enrollmentDate;
}

std::string Enrollment::getStatus() const {
    return status;
}

void Enrollment::setStatus(const std::string& status) {
    if (status != "Active" &&
        status != "Completed" &&
        status != "Cancelled") {
        throw std::invalid_argument("Invalid enrollment status.");
    }

    this->status = status;
}

bool Enrollment::isActive() const {
    return status == "Active";
}
