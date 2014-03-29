#include "Plugin.hpp"
#include "PluginFactory.hpp"
#include "Module.hpp"
#include "LinuxLibraryLoader.hpp"
#include "gtest/gtest.h"

TEST(Configuration, list)
{
	EXPECT_NO_THROW(PluginFactory<Module>::getInstance()->loadPluginsFromFile("libtestplugin.so"));
	
	std::vector<std::string> loadedModules=PluginFactory<Module>::getInstance()->getRegisteredPlugins();
	EXPECT_EQ(loadedModules.size(),(unsigned int)1);
	EXPECT_EQ(loadedModules[0],"TestPlugin");
}
