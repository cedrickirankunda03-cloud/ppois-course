#pragma once
#include <string>
#include <vector>
#include "Shelf.hpp"

namespace wms {

class Rack {
    std::string id_;
    std::vector<Shelf> shelves_;
public:
    explicit Rack(std::string id);
    
    void addShelf(const Shelf& shelf);
    const std::string& id() const noexcept { return id_; }
    size_t shelfCount() const noexcept { return shelves_.size(); }
};

} // namespace wms