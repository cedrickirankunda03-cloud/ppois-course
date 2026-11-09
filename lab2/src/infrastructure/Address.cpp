#include "infrastructure/Address.h"

#include <stdexcept>
#include <sstream>

Address::Address(
    const std::string& addressId,
    const std::string& street,
    const std::string& city,
    const std::string& postalCode,
    const std::string& country)
    : addressId(addressId),
      street(street),
      city(city),
      postalCode(postalCode),
      country(country)
{
    if (addressId.empty() ||
        street.empty() ||
        city.empty() ||
        postalCode.empty() ||
        country.empty())
    {
        throw std::invalid_argument(
            "Address information cannot be empty"
        );
    }
}

std::string Address::getAddressId() const
{
    return addressId;
}

std::string Address::getFullAddress() const
{
    std::ostringstream result;

    result << street << ", "
           << city << ", "
           << postalCode << ", "
           << country;

    return result.str();
}

bool Address::operator==(const Address& other) const
{
    return addressId == other.addressId &&
           street == other.street &&
           city == other.city &&
           postalCode == other.postalCode &&
           country == other.country;
}

bool Address::operator!=(const Address& other) const
{
    return !(*this == other);
}
void Address::updateAddress(
    const std::string& street,
    const std::string& city,
    const std::string& postalCode,
    const std::string& country)
{
    if (street.empty() ||
        city.empty() ||
        postalCode.empty() ||
        country.empty())
    {
        throw std::invalid_argument(
            "Address information cannot be empty"
        );
    }

    this->street = street;
    this->city = city;
    this->postalCode = postalCode;
    this->country = country;
}