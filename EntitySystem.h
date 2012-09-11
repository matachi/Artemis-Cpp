#ifndef ENTITY_SYSTEM_H
#define ENTITY_SYSTEM_H

#include <bitset>
#include "BitSize.h"
#include "Component.h"
#include <iostream>
#include <assert.h>
#include <typeinfo>
#include <bitset>
#include "ImmutableBag.h"
//#include "Entity.h"
#include "ComponentTypeManager.h"


namespace artemis {
  
	class Entity;
	class World;
  
	/**
   * The most raw entity system. It should not typically be used, but you can create your own
   * entity system handling by extending this. It is recommended that you use the other provided
   * entity system implementations.
   */
	class EntitySystem {
  public:
    void printTypeFlag() {
      std::cout << typeFlags;
    }
    std::bitset<BITSIZE> getSystemBit() {
      return systemBit;
    }
    void setSystemBit(std::bitset<BITSIZE> bit);
    virtual ~EntitySystem();
    /*override these functions*/
    virtual void initialize() {};
    void setWorld(World *world);
    void change(Entity &e);
    void process();
    int getEntityCount();
  protected:
    EntitySystem() { this->world = nullptr; };
    World * world;
    /**
     * Call this in the constructor of the derived system
     */
    template<typename...components>
    void setComponentTypes() {
      addToTypeFlag(typelist<components...>());
    }
    /*override these functions*/
    virtual void begin() {};
    virtual void end() {};
    virtual void removed(Entity &e) {};
    virtual void added(Entity &e) {};
    //Abstracts
    virtual void processEntities(ImmutableBag<Entity*> & bag) = 0;
    virtual bool checkProcessing() = 0;
  private:
    std::bitset<BITSIZE> systemBit;
    std::bitset<BITSIZE> typeFlags;
    Bag<Entity*> actives;
    void remove(Entity &e);
    //============================================================
    //Meta templates. Helps with passing each type from the variadic template
    /*
     *Struct to pass rest the types
     */
    template<typename...>
    struct typelist {};
    /*
     * Recursively called. On each iteration  "component" is set to the next "typename" from rest pack set. .
     * We pass this component into our ComponentManager.
     */
    template<typename component, typename ... Rest>
    void addToTypeFlag(typelist<component,Rest...>) {
      //Add Bits to typeflags
      typeFlags |= ComponentTypeManager::getBit<component>();
      addToTypeFlag(typelist<Rest...>());
    };
    /**
     * addToTypeFlag is called recursively. This defines the end condition.
     * When our typelist has no types left from the pack, the call will end.
     */
    void addToTypeFlag(typelist<>) { };
	};
  
};


#endif
