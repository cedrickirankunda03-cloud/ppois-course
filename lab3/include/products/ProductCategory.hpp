#pragma once
#include <string>
namespace wms {
class ProductCategory {
    std::string name_;
public:
    explicit ProductCategory(std::string name) : name_(std::move(name)) {}
    const std::string& name() const noexcept { return name_; }
};
}
