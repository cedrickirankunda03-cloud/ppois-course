#ifndef DEANERY_EXCEPTION_H
#define DEANERY_EXCEPTION_H

#include <stdexcept>
#include <string>

class DeaneryException : public std::runtime_error {
public:
    explicit DeaneryException(const std::string& message);
    ~DeaneryException() override = default;
};

#endif