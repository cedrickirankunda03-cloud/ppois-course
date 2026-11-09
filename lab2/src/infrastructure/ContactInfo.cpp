#include "infrastructure/ContactInfo.h"

#include <stdexcept>

ContactInfo::ContactInfo(
    const std::string& contactId,
    const std::string& phoneNumber,
    const std::string& email)
    : contactId(contactId),
      phoneNumber(phoneNumber),
      email(email)
{
    if (contactId.empty() ||
        phoneNumber.empty() ||
        email.empty())
    {
        throw std::invalid_argument(
            "Contact information cannot be empty"
        );
    }
}

std::string ContactInfo::getContactId() const
{
    return contactId;
}

std::string ContactInfo::getPhoneNumber() const
{
    return phoneNumber;
}

std::string ContactInfo::getEmail() const
{
    return email;
}

void ContactInfo::updatePhoneNumber(
    const std::string& phoneNumber)
{
    if (phoneNumber.empty())
    {
        throw std::invalid_argument(
            "Phone number cannot be empty"
        );
    }

    this->phoneNumber = phoneNumber;
}

void ContactInfo::updateEmail(
    const std::string& email)
{
    if (email.empty())
    {
        throw std::invalid_argument(
            "Email cannot be empty"
        );
    }

    this->email = email;
}