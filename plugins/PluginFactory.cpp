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
	if (_producers.find(producer->getName())==_producers.end())
	{
		_producers[producer->getName()]=producer;
	}
	else
	{
		throw std::string("plugin with name '"+producer->getName()+"' already loaded");
	}
}

template<class PRODUCT>
Plugin<PRODUCT>* PluginFactory::getPlugin(std::string name)
{
	if (_producers.find(name)!=_producers.end())
	{
		Plugin<PRODUCT>* plugin = dynamic_cast<Plugin<PRODUCT>*>(_producers[name]);
		if (!plugin)
		{
			throw std::string("plugin with name '"+name+"' is not casted to the its correct type");
		}
		return plugin;
	}
	else
	{
		throw std::string("plugin with name '"+name+"' not found");
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

