#include "ComponentTypeManager.h"

namespace artemis {
	ComponentType & ComponentTypeManager::getTypeFor(const std::type_info &t) {
		ComponentType * type = componentTypes[&t];
    
		if(type == NULL) {
			type = new ComponentType();
			componentTypes[&t] = type;
		}
    
		return *type;
	};
	
	void ComponentTypeManager::deleteComponentTypes(){
    
		std::tr1::unordered_map<const std::type_info*,ComponentType*,type_info_hash>::iterator it;
		
		for(it = componentTypes.begin(); it != componentTypes.end(); it++)
		{
			delete it->second;
		}
		componentTypes.clear();
	}
  
	std::tr1::unordered_map<const std::type_info*,ComponentType*, type_info_hash>ComponentTypeManager::componentTypes;
}
