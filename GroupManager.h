#ifndef GROUP_MANAGER_H
#define GROUP_MANAGER_H

#include "ImmutableBag.h"
#include <unordered_map>
#include <string>

namespace artemis {
	
	class Entity;
	
	class GroupManager {
	private:
		Bag<Entity*> empty_bag;
		std::string empty_string;
		Bag<std::string*> groupByEntity;
		std::unordered_map<std::string, Bag<Entity*>*> entitiesByGroup;
	public:
		GroupManager();
		~GroupManager();
		void set(std::string group, Entity& e);
		void remove(Entity& e);
		std::string getGroupOf(Entity& e);
		bool isGrouped(Entity& e);
		bool isInGroup(std::string group, Entity& e);
		ImmutableBag<Entity*>* getEntities(std::string group);
	};
};

#endif // $(Guard token)