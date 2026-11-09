 #pragma once

#include <string>

class ContactInfo
{
private:
    std::string contactId;
    std::string phoneNumber;
    std::string email;

public:
    ContactInfo(const std::string& contactId,
                const std::string& phoneNumber,
                const std::string& email);

    std::string getContactId() const;
    std::string getPhoneNumber() const;
    std::string getEmail() const;

    void updatePhoneNumber(const std::string& phoneNumber);
    void updateEmail(const std::string& email);
};