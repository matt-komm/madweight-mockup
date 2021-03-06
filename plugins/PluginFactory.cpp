#include "PluginFactory.hpp"

#include "Module.hpp"
#include "Algorithm.hpp"

PluginFactory::PluginFactory():
	_libLoader()
{

}

PluginFactory*  PluginFactory::getInstance()
{
	static PluginFactory factory;
	return &factory;
}

std::vector<std::string> PluginFactory::getRegisteredPluginNames()
{
	std::vector<std::string> list;
	for (auto it = _producers.begin(); it!= _producers.end(); ++it )
	{
		list.push_back(it->first);
	}
	return list;
}

void PluginFactory::registerPlugin(AbstractPlugin* producer)
{
	if (_producers.find(producer->getPluginName())==_producers.end())
	{
		_producers[producer->getPluginName()]=producer;
	}
	else
	{
		throw std::string("plugin with name '"+producer->getPluginName()+"' already loaded");
	}
}

template<class BASECLASS>
Plugin<BASECLASS>* PluginFactory::getPlugin(std::string pluginName)
{
	if (_producers.find(pluginName)!=_producers.end())
	{
		Plugin<BASECLASS>* plugin = dynamic_cast<Plugin<BASECLASS>*>(_producers[pluginName]);
		if (!plugin)
		{
			throw std::string("plugin with name '"+pluginName+"' is of type '"+_producers[pluginName]->getPluginBaseName()+"'");
		}
		return plugin;
	}
	else
	{
		throw std::string("plugin with name '"+pluginName+"' not found");
	}
}
template Plugin<Module>* PluginFactory::getPlugin<Module>(std::string name);
template Plugin<Algorithm>* PluginFactory::getPlugin<Algorithm>(std::string name);

void PluginFactory::loadPluginsFromFile(std::string file)
{
	_libLoader.loadLibrary(file);
}

PluginFactory::~PluginFactory()
{
}

