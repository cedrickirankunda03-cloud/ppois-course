
#include "students/StudentProfile.h"

#include <stdexcept>

StudentProfile::StudentProfile(
    const std::string& studentId,
    const std::string& email,
    const std::string& phoneNumber,
    const std::string& address
)
    : studentId(studentId),
      email(email),
      phoneNumber(phoneNumber),
      address(address)
{
    if (studentId.empty())
    {
        throw std::invalid_argument(
            "Student ID cannot be empty."
        );
    }
}

const std::string& StudentProfile::getStudentId() const
{
    return studentId;
}

const std::string& StudentProfile::getEmail() const
{
    return email;
}

const std::string& StudentProfile::getPhoneNumber() const
{
    return phoneNumber;
}

const std::string& StudentProfile::getAddress() const {
    return address;
}

void StudentProfile::setEmail(const std::string& email)
{
    if (email.empty())
    {
        throw std::invalid_argument("Email cannot be empty.");
    }

    this->email = email;
}

void StudentProfile::setPhoneNumber(
    const std::string& phoneNumber
)
{
    if (phoneNumber.empty())
    {
        throw std::invalid_argument(
            "Phone number cannot be empty."
        );
    }

    this->phoneNumber = phoneNumber;
}

void StudentProfile::setAddress(const std::string& address)
{
    if (address.empty())
    {
        throw std::invalid_argument("Address cannot be empty.");
    }

    this->address = address;
}
