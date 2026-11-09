#pragma once

#include <string>

class Address
{
private:
    std::string addressId;
    std::string street;
    std::string city;
    std::string postalCode;
    std::string country;

public:
    Address(
        const std::string& addressId,
        const std::string& street,
        const std::string& city,
        const std::string& postalCode,
        const std::string& country
    );

    std::string getAddressId() const;
    std::string getFullAddress() const;

    bool operator==(const Address& other) const;
    bool operator!=(const Address& other) const;

    void updateAddress(
        const std::string& street,
        const std::string& city,
        const std::string& postalCode,
        const std::string& country
    );
};