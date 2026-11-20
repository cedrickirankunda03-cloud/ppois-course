
#ifndef STUDENT_PROFILE_H
#define STUDENT_PROFILE_H

#include <string>

class StudentProfile
{
private:
    std::string studentId;
    std::string email;
    std::string phoneNumber;
    std::string address;

public:
    StudentProfile(
        const std::string& studentId,
        const std::string& email,
        const std::string& phoneNumber,
        const std::string& address
    );

    const std::string& getStudentId() const;
    const std::string& getEmail() const;
    const std::string& getPhoneNumber() const;
    const std::string& getAddress() const;

    void setEmail(const std::string& email);
    void setPhoneNumber(const std::string& phoneNumber);
    void setAddress(const std::string& address);
};

#endif
