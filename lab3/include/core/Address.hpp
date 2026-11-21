#pragma once
#include <string>
namespace wms { namespace core {
class Address {
    std::string street_, city_, postalCode_, country_;
public:
    Address(std::string street, std::string city, std::string postalCode, std::string country);
    const std::string& street() const noexcept { return street_; }
    const std::string& city() const noexcept { return city_; }
    const std::string& postalCode() const noexcept { return postalCode_; }
    const std::string& country() const noexcept { return country_; }
    std::string format() const;
};
}}
