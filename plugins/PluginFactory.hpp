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
        template<class BASECLASS> Plugin<BASECLASS>* getPlugin(std::string pluginName);
		void loadPluginsFromFile(std::string file);

		inline bool hasPlugin(std::string name)
		{
			return _producers.find(name) != _producers.end();
		}

        ~PluginFactory();
};

#endif

