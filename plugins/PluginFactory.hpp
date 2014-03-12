#ifndef __PLUGINFACTORY_H__
#define __PLUGINFACTORY_H__

#include "Plugin.hpp"
#include "LibraryLoader.hpp"

#include <vector>
#include <map>
#include <string>

template<class PRODUCT>
class PluginFactory
{
	protected:
		std::map<std::string, const Producer<PRODUCT>*> _producers;
		LibraryLoader _libLoader;
		PluginFactory();
    public:
		static PluginFactory<PRODUCT>* getInstance();
		std::vector<std::string> getRegisteredPlugins();
        void registerPlugin(const Producer<PRODUCT>* producer);
		const PRODUCT* createPlugin(std::string name, Configuration conf);
		void loadPluginsFromFile(std::string file);
        ~PluginFactory();
};

#endif

