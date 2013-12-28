#ifndef __PLUGIN_H__
#define __PLUGIN_H__

#include "Module.hpp"
#include "Configuration.hpp"

#include <vector>
#include <string>
#include <typeinfo>

template<class PRODUCT>
class Producer
{
    public:
		Producer()
        {
        }
        
        virtual ~Producer()
        {
        }
        
        virtual std::string getPluginBaseName()
        {
            return "Module";
        }
        
        virtual PRODUCT* create(Configuration conf) const =0;

        virtual std::string getName() const =0;
};

template<class PLUGINCLASS>
class ModuleProducer:
	public Producer<Module>
{
	protected:
		const std::string _pluginName;
    public:
		ModuleProducer(std::string pluginName):
			_pluginName(pluginName)
        {
        }

        virtual ~ModuleProducer()
        {
        }

        virtual Module* create(Configuration conf) const
        {
        	return new PLUGINCLASS(conf);
        }

        virtual std::string getName() const
        {
        	return _pluginName;
        }
};

#endif

