#include "exceptions/DeaneryException.h"

DeaneryException::DeaneryException(const std::string& message)
    : std::runtime_error(message)
{
}
