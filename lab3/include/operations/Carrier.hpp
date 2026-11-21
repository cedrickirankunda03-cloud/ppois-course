#pragma once
#include <string>
namespace wms {
class Carrier {
    std::string name_;
public:
    explicit Carrier(std::string name) : name_(std::move(name)) {}
    const std::string& name() const noexcept { return name_; }
};
}
