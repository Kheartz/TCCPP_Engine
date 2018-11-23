#include "Component.hpp"
#include "Entity.hpp"
#include <string>
struct Health {
  int health = 0;
  int max_health = 0;
};

struct SomeUserConstructedStruct {
  int someInt;
  std::string someStr;
  SomeUserConstructedStruct(int i, std::string str)
      : someInt(i), someStr(str) {}
};

int main() {
  TCCPP::EntityManager eManager;
  auto someRandomEntity = eManager.createEntity();
  TCCPP::ComponentManager<SomeUserConstructedStruct> cManagerSUCS;
  cManagerSUCS.emplaceComponent(someRandomEntity, 4, "Hello Mate");
  return 0;
}
