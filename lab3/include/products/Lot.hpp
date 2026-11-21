#pragma once
#include <string>
namespace wms {
class Lot {
    std::string lotNumber_;
public:
    explicit Lot(std::string lotNumber) : lotNumber_(std::move(lotNumber)) {}
    const std::string& number() const noexcept { return lotNumber_; }
};
}
