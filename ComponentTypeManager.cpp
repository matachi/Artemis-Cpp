#include "ComponentTypeManager.h"

namespace artemis {
	ComponentType & ComponentTypeManager::getTypeFor(const std::type_info &t) {
		ComponentType * type = componentTypes[t.hash_code()];

		if(type == nullptr) {
			type = new ComponentType();
			componentTypes[t.hash_code()] = type;
		}

		return *type;
	};
	
	void ComponentTypeManager::deleteComponentTypes(){
		 
		std::unordered_map<size_t,ComponentType*>::iterator it;
		
		for(it = componentTypes.begin(); it != componentTypes.end(); it++)
		{
			delete it->second;
		}
		componentTypes.clear();
	}

	std::unordered_map<size_t,ComponentType*>ComponentTypeManager::componentTypes;
}
