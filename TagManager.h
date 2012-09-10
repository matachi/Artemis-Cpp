#ifndef TAG_MANAGER_H
#define TAG_MANAGER_H


#include <unordered_map>
#include <string>

namespace artemis {

	//class World;
	class Entity;

	class TagManager {
		private:
			//World * world;
			std::unordered_map<std::string, Entity*> tagByEntity;
		public:
			//TagManager(World &world);
			TagManager();
			void subscribe(const std::string tag, Entity &e);
			void unSubscribe(const std::string tag);
			bool isSubscribed(const std::string tag);
			Entity & getEntity(const std::string tag);
			void remove(Entity &e);
	};
};
#endif // $(Guard token)
