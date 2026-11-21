#pragma once
#include <string>
namespace wms {
class ValidationResult {
    bool ok_;
    std::string message_;
    explicit ValidationResult(bool ok, std::string message) : ok_(ok), message_(std::move(message)) {}
public:
    static ValidationResult success() { return ValidationResult(true, {}); }
    static ValidationResult failure(std::string msg) { return ValidationResult(false, std::move(msg)); }
    bool ok() const noexcept { return ok_; }
    const std::string& message() const noexcept { return message_; }
    explicit operator bool() const noexcept { return ok_; }
};
}
