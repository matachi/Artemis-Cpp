#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H

#include <unordered_map>
#include "ImmutableBag.h"
#include "TypeInfoHash.h"
#include <iostream>
namespace artemis {
  
	class EntitySystem;
	class Entity;
	class World;
  
	class SystemManager {
  public:
    SystemManager(World &world);
    ~SystemManager();
    void initializeAll();
    Bag<EntitySystem*> & getSystems();
    EntitySystem* setSystem(EntitySystem * stm);
    
    template<typename eSystem>
    EntitySystem* getSystem() {
      return (eSystem*)(systems[typeid(eSystem).hash_code()]);
    }
    
  private:
    World * world;
    std::unordered_map<const std::type_info*, EntitySystem*, type_info_hash> systems;
    Bag<EntitySystem*> bagged;
	};
};
#endif // $(Guard token)
