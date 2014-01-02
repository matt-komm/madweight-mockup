#include "Module.hpp"
#include "Configuration.hpp"
#include "Scalar.hpp"
#include "Plugin.hpp"
#include "PluginFactory.hpp"

#include <iostream>

class TestPlugin:
	public Module
{

	protected:
		Scalar* _output;
		const Scalar* _input;
	public:
		TestPlugin(Configuration conf):
			Module(conf)
		{
			_output=createVariable<Scalar>("out");
			_input=getVariable<Scalar>("in");
		}

		virtual void execute()
		{
			_output->value()=_input->value()*10;
		}

		~TestPlugin()
		{

		}
};

PLUGIN_INIT(Module,TestPlugin)
/*
extern "C"
{
	void initialize()
	{
		//std::cout<<"hello lib"<<std::endl;

		static ModuleProducer<TestPlugin> _testplugin("TestPlugin");
		PluginFactory<Module>::getInstance()->registerPlugin(&_testplugin);

	}
}
*/
