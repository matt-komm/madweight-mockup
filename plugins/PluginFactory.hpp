#ifndef __PLUGINFACTORY_H__
#define __PLUGINFACTORY_H__

#include "Plugin.hpp"
#include "LibraryLoader.hpp"


#include <vector>
#include <map>
#include <string>

class PluginFactory
{
	protected:
		std::map<std::string, AbstractPlugin*> _producers;
		LibraryLoader _libLoader;
		PluginFactory();
    public:
		static PluginFactory* getInstance();
		std::vector<std::string> getRegisteredPluginNames();
        void registerPlugin(AbstractPlugin* producer);
        template<class PRODUCT> Plugin<PRODUCT>* getPlugin(std::string name);
		void loadPluginsFromFile(std::string file);
        ~PluginFactory();
};

#endif

