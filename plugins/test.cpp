#include "Plugin.hpp"
#include "PluginFactory.hpp"
#include "Module.hpp"
#include "LinuxLibraryLoader.hpp"

#include <iostream>

int main()
{
	try
	{
		PluginFactory<Module>::getInstance()->loadPluginsFromFile("libtestplugin.so");
	} catch (std::string e) {
		std::cout<<e<<std::endl;
	}
	std::vector<std::string> loadedModules=PluginFactory<Module>::getInstance()->getRegisteredPlugins();
	for (unsigned int i=0; i<loadedModules.size();++i)
	{
		std::cout<<loadedModules[i]<<std::endl;
	}
    return 0;
}
