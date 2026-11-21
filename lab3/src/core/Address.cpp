#include "core/Address.hpp"
#include "exceptions/WarehouseException.hpp"
namespace wms { namespace core {
Address::Address(std::string street, std::string city, std::string postalCode, std::string country)
    : street_(std::move(street)), city_(std::move(city)), postalCode_(std::move(postalCode)), country_(std::move(country)) {
    if (street_.empty() || city_.empty() || postalCode_.empty() || country_.empty())
        throw WarehouseException("address fields must not be empty");
}
std::string Address::format() const { return street_ + ", " + city_ + " " + postalCode_ + ", " + country_; }
}}
