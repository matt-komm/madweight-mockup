#include "Plugin.hpp"
#include "PluginFactory.hpp"
#include "Module.hpp"
#include "LinuxLibraryLoader.hpp"
#include "gtest/gtest.h"

TEST(Plugin, loadingModule)
{
	PluginFactory* factory = PluginFactory::getInstance();
	//EXPECT_NO_THROW(
	try
	{
		factory->loadPluginsFromFile("./libsampleplugin.so");
	}catch (std::string s)
	{
		std::cout<<s<<std::endl;
	}
	/*
							//);
	std::vector<std::string> loadedModules=factory->getRegisteredPluginNames();
	EXPECT_EQ(loadedModules.size(),(unsigned int)1);
	Plugin<Module>* plugin = factory->getPlugin<Module>("TestModule");
	Module* m = plugin->create(Configuration::createEmptyDict());
	std::cout<<m->getOutputSize()<<std::endl;
	std::cout<<m->getOutput(0)->getName()<<std::endl;
	//EXPECT_EQ(loadedModules[0],"TestModule");

	 */
}
