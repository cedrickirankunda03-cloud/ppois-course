#pragma once
#include <string>
namespace wms {
class Entity {
protected:
    std::string id_;
    explicit Entity(std::string id) : id_(std::move(id)) {}
public:
    virtual ~Entity() = default;
    const std::string& id() const noexcept { return id_; }
    bool operator==(const Entity& other) const noexcept { return id_ == other.id_; }
    bool operator!=(const Entity& other) const noexcept { return !(*this == other); }
};
}
