#include "TagManager.h"
//#include "World.h"
#include "Entity.h"

namespace artemis {

	TagManager::TagManager() {
		//this->world = &world;
	}

	Entity& TagManager::getEntity(const std::string tag) {
		return *tagByEntity[tag];
	}

	bool TagManager::isSubscribed(const std::string tag) {
		return (tagByEntity[tag] != nullptr);
	}

	void TagManager::remove(Entity &e) {
		
		//TODO find cleaner way to remove by value
		Entity * ent = &e;
		for(auto& it: tagByEntity){
			if(it.second == ent){
				tagByEntity.erase(it.first);
				return;
			}
		}
		
	}

	void TagManager::unSubscribe(const std::string tag) {
		//tagByEntity[tag] = nullptr;
		tagByEntity.erase(tag);
	}
	
	void TagManager::subscribe(std::string tag, Entity &e){
		remove(e);
		tagByEntity[tag] = &e;
	}

}
