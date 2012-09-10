#include "GroupManager.h"
#include "Entity.h"
//#include <string.h>

namespace artemis {
	GroupManager::GroupManager() : empty_bag(1) {
		empty_string.clear();
	}

	ImmutableBag<Entity*> * GroupManager::getEntities(std::string group) {
		Bag<Entity*> * bag = entitiesByGroup[group];
		if(bag == nullptr) {
      // create a new empty group
      bag = new Bag<Entity*>(32);
      entitiesByGroup[group] = bag;
    }
		return bag;
	}

	std::string GroupManager::getGroupOf(Entity& e) {
		if(e.getId() < groupByEntity.getCapacity()){
			std::string * group = groupByEntity.get(e.getId());
			if(group == nullptr) 
				return empty_string;
			return  *group;
		}
		return empty_string;
	}

	bool GroupManager::isGrouped(Entity& e) {
		return !getGroupOf(e).empty();
	}

	bool GroupManager::isInGroup(std::string group, Entity& e) {
		//TODO ignore case
		//return strncasecmp(group, getGroupOf(e)) == 0;
		return group.compare(getGroupOf(e)) == 0;
	}

	void GroupManager::remove(Entity& e) {
		if(e.getId() < groupByEntity.getCapacity()){
			
			std::string * groupId = groupByEntity.get(e.getId());
			if(groupId != nullptr){
				groupByEntity.set(e.getId(), nullptr);
				
				Bag<Entity*> * entities = entitiesByGroup[*groupId];
				if(entities != nullptr){
					entities->remove(&e);
				}
				entities = nullptr;
				delete groupId;
				groupId = nullptr;
			}
			groupId = nullptr;
			
		}
	}

	void GroupManager::set(std::string group, Entity& e) {
		remove(e);
		
		Bag<Entity*> * entities = entitiesByGroup[group];
		if(entities == nullptr){
			entities = new Bag<Entity*>(32);
			entitiesByGroup[group] = entities;
		}
		entities->add(&e);
		entities = nullptr;
		groupByEntity.set(e.getId(), new std::string(group));
		
	}
	
	GroupManager::~GroupManager(){
		
		groupByEntity.deleteData();
		
		//groupByEntity.clear();
		
		std::unordered_map<std::string, Bag<Entity*>*>::iterator it;
			
			for(it = entitiesByGroup.begin(); it != entitiesByGroup.end(); it++)
			{
				delete it->second;
			}

		entitiesByGroup.clear();
	}

};
