#ifndef __LIBRARYLOADER_H__
#define __LIBRARYLOADER_H__

//hides casts from the compiler
template<typename INPTR, typename OUTPTR>
class SharedMemory
{
	private:
		union Memory
		{
			INPTR iptr;
			OUTPTR optr;
		} _memory;

	public:
		SharedMemory(INPTR inptr)
		{
			_memory.iptr=inptr;
		}

		OUTPTR get()
		{
			return _memory.optr;
		}
};

//TODO: add cmake macro to add define statements with 'add_definition' to recognize the platform correctly
#ifndef WIN32
#define LIBLOADERFOUND
#include "LinuxLibraryLoader.hpp"
typedef LinuxLibraryLoader LibraryLoader;
#else
//....
#endif

#ifndef LIBLOADERFOUND
#error "no suited library loader found or system not regonized"
#endif

#include "Plugin.hpp"
#include "PluginFactory.hpp"
#include <iostream>
#include <string>

#define REGISTER_PLUGIN(BASECLASS,USERCLASS) \
	/*std::cout<<"REGISTER_PLUGIN: "<< #BASECLASS <<","<< #USERCLASS <<std::endl;*/ \
	static ConcretePlugin<BASECLASS,USERCLASS>  _ ## BASECLASS ## ## USERCLASS ## plugin(#USERCLASS, #BASECLASS); \
	PluginFactory::getInstance()->registerPlugin(&_ ## BASECLASS ## ## USERCLASS ## plugin); \

#define INIT(PLUGINS) \
	extern "C" \
	{ \
		void initialize() \
		{ \
			PLUGINS \
		} \
	} \


#endif

