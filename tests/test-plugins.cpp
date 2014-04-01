#include "Plugin.hpp"
#include "PluginFactory.hpp"
#include "Module.hpp"
#include "Algorithm.hpp"
#include "Graph.hpp"
#include "LinuxLibraryLoader.hpp"
#include "gtest/gtest.h"

TEST(PluginFactory, loadPlugins)
{
	PluginFactory* factory = PluginFactory::getInstance();
	EXPECT_NO_THROW(factory->loadPluginsFromFile("./libsampleplugin.so"));
	std::vector<std::string> loadedModules=factory->getRegisteredPluginNames();
	EXPECT_EQ(loadedModules.size(),(unsigned int)2);
	EXPECT_EQ(factory->hasPlugin("TestModule"),true);
	EXPECT_EQ(factory->hasPlugin("TestAlgorithm"),true);
	EXPECT_THROW(factory->getPlugin<Algorithm>("TestModule"),std::string);

	Plugin<Module>* modulePlugin = factory->getPlugin<Module>("TestModule");
	Module* testModule = modulePlugin->create(Configuration::createEmptyDict());
	EXPECT_EQ(testModule->getOutputSize(),(unsigned int)1);
	EXPECT_EQ(testModule->getOutput(0)->getName(),"out");

	Plugin<Algorithm>* algorithmPlugin = factory->getPlugin<Algorithm>("TestAlgorithm");
	Algorithm* testAlgorithm = algorithmPlugin->create(Configuration::createEmptyDict());
	Graph g;
	testAlgorithm->setGraph(g);
	testAlgorithm->execute();
}
