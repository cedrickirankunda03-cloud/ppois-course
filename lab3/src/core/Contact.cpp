#include "core/Contact.hpp"
#include "exceptions/WarehouseException.hpp"
#include <regex>
namespace wms { namespace core {
Contact::Contact(std::string email, std::string phone) : email_(std::move(email)), phone_(std::move(phone)) {
    static const std::regex emailPattern(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
    if (!std::regex_match(email_, emailPattern)) throw WarehouseException("invalid email: '" + email_ + "'");
    if (phone_.empty()) throw WarehouseException("phone must not be empty");
}
bool Contact::isValid() const noexcept { return !email_.empty() && !phone_.empty() && email_.find('@') != std::string::npos; }
}}
