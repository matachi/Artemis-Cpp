#ifndef SYSBITMANAGER_H
#define SYSBITMANAGER_H

#include <typeinfo>
#include <bitset>
#include <unordered_map>
#include "BitSize.h"

namespace artemis {
	
	class EntitySystem;
	
	class SystemBitManager {
		private:
			static int POS;
			static std::unordered_map< size_t, std::bitset<BITSIZE>* > systemBits;

		public:

			static std::bitset<BITSIZE> & getBitFor(const std::type_info & type);
			static void removeBitSets();
			template<typename system>
			static std::bitset<BITSIZE> & getBitFor() {

				assert((std::is_base_of< EntitySystem, system >::value == true));

				return getBitFor(typeid(system));

			}
			
	};

};
#endif // $(Guard token)
