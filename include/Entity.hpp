#pragma once

#include <cstddef>

namespace TCCPP {

using EntityID = std::size_t;

class EntityManager {
private:
  class Entity {
  private:
    EntityID id;
    inline static std::size_t totalEntities = 0;

  public:
    Entity() : id(totalEntities++) {}
    Entity(const Entity &) = delete;
    Entity &operator=(const Entity &) = delete;
    const EntityID getID() const { return id; }
  };

public:
  EntityID createEntity() { return Entity{}.getID(); }
};
} // namespace TCCPP
