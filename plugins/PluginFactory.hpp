#ifndef __PLUGINFACTORY_H__
#define __PLUGINFACTORY_H__

#include "Plugin.hpp"

#include <vector>
#include <unordered_map>
#include <string>

template<class PRODUCT>
class PluginFactory
{
	protected:
		std::unordered_map<std::string, const Producer<PRODUCT>*> _producers;

		PluginFactory()
		{

		}
    public:
		static PluginFactory<PRODUCT>* getInstance()
		{
			static PluginFactory<PRODUCT> factory;
			return &factory;
		}
		
        void registerPlugin(const Producer<PRODUCT>* producer)
		{
			if (_producers.find(producer->getName())!=_producers.end())
			{
				_producers[producer->getName()]=producer;
			}
			else
			{
				throw std::string("plugin with name '"+producer->getName()+"' already loaded");
			}
		}


		const PRODUCT* createPlugin(std::string name, Configuration conf)
		{
			if (_producers.find(name)!=_producers.end())
			{
				return _producers[name].create(conf);
			}
			else
			{
				throw std::string("plugin with name '"+name+"' not found");
			}
		}
		/*
		void loadPluginsFromFile(std::string file)
		{
			//todo load plugins from libraries and execute init function
			// init function should then call 'registerPlugin'


		}
		*/
        ~PluginFactory()
        {

        }
};

#endif

