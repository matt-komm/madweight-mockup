#include "PluginFactory.hpp"

template<class PRODUCT> PluginFactory<PRODUCT>::PluginFactory():
	_libLoader()
{

}

template<class PRODUCT> PluginFactory<PRODUCT>*  PluginFactory<PRODUCT>::getInstance()
{
	static PluginFactory<PRODUCT> factory;
	return &factory;
}

template<class PRODUCT> std::vector<std::string> PluginFactory<PRODUCT>::getRegisteredPluginNames()
{
	std::vector<std::string> list;
	for (auto it = _producers.begin(); it!= _producers.end(); ++it )
	{
		list.push_back(it->first);
	}
	return list;
}

template<class PRODUCT> void PluginFactory<PRODUCT>::registerPlugin(const Producer<PRODUCT>* producer)
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

template<class PRODUCT> const PRODUCT* PluginFactory<PRODUCT>::createPlugin(std::string name, Configuration conf)
{
	if (_producers.find(name)!=_producers.end())
	{
		const Producer<PRODUCT>* producer = _producers[name];
		return producer->create(conf);
	}
	else
	{
		throw std::string("plugin with name '"+name+"' not found");
	}
}

template<class PRODUCT> void PluginFactory<PRODUCT>::loadPluginsFromFile(std::string file)
{
	_libLoader.loadLibrary(file);
}

template<class PRODUCT> PluginFactory<PRODUCT>::~PluginFactory()
{
}

template class Producer<Module>;
template class PluginFactory<Module>;
