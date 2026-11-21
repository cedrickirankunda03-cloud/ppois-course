#pragma once
#include <string>
namespace wms { namespace core {
class Contact {
    std::string email_, phone_;
public:
    Contact(std::string email, std::string phone);
    const std::string& email() const noexcept { return email_; }
    const std::string& phone() const noexcept { return phone_; }
    bool isValid() const noexcept;
};
}}
