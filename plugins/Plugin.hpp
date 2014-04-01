#ifndef __PLUGIN_H__
#define __PLUGIN_H__

#include "Module.hpp"
#include "Configuration.hpp"

#include <vector>
#include <string>
#include <typeinfo>

template<class PRODUCT> class Plugin;

class AbstractPlugin
{
	private:
		std::string _name;
	public:
		AbstractPlugin(std::string name):
		_name(name)
		{
		}

		inline std::string getName() const
		{
			return _name;
		}

		virtual ~AbstractPlugin()
		{
		}
};


template<class PRODUCT>
class Plugin:
	public AbstractPlugin
{
	public:
		Plugin<PRODUCT>(std::string name):
			AbstractPlugin(name)
		{
		}

		virtual PRODUCT* create(Configuration& conf) = 0;
};

template<class PRODUCT, class PLUGINCLASS>
class ConcretePlugin:
	public Plugin<PRODUCT>
{
	public:
		ConcretePlugin<PRODUCT, PLUGINCLASS>(std::string name):
			Plugin<PRODUCT>(name)
		{
		}

		virtual PRODUCT* create(Configuration& conf)
		{
			return new PLUGINCLASS(conf);
		}
};

#endif

