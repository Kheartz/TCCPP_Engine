#include "Entity.hpp"
#include <unordered_map>
#include <vector>

namespace TCCPP {

template <typename T> class ComponentManager {
public:
  using componentIdx = std::size_t;

private:
  std::unordered_map<EntityID, componentIdx> componentMap;
  std::vector<T> components;

public:
  T &getComponent(EntityID e) { return componentMap[e]; }
  std::vector<T> &getComponents() { return components; }
  template<typename... ComponentArgTs>
  void emplaceComponent(EntityID eID, ComponentArgTs&&... compArgs){
    components.emplace_back(std::forward<ComponentArgTs>(compArgs)...);
    componentMap.emplace(eID, components.size() - 1);
  }
};

} // namespace TCCPP
