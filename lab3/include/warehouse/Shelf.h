#pragma once
#include <string>
#include <vector>
#include "Bin.hpp"

namespace wms {

class Shelf {
    std::string id_;
    std::vector<Bin> bins_;
public:
    explicit Shelf(std::string id);
    
    void addBin(const Bin& bin);
    const std::string& id() const noexcept { return id_; }
    size_t binCount() const noexcept { return bins_.size(); }
};

} // namespace wms