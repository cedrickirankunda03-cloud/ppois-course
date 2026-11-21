#include "warehouse/Rack.hpp"
namespace wms {
Rack::Rack(std::string id) : id_(std::move(id)) {}
void Rack::addShelf(const Shelf& shelf) { shelves_.push_back(shelf); }
}
