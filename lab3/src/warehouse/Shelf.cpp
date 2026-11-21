#include "warehouse/Shelf.hpp"
namespace wms {
Shelf::Shelf(std::string id) : id_(std::move(id)) {}
void Shelf::addBin(const Bin& bin) { bins_.push_back(bin); }
}
