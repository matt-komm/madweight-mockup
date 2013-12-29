#ifndef __LINUXLIBRARYLOADER_H__
#define __LINUXLIBRARYLOADER_H__

#include "LibraryLoader.hpp"

#include <string>
#include <unordered_map>
#include <dlfcn.h>

class LinuxLibraryLoader:
	public AbstractLibraryLoader
{
    protected:
		typedef void (*init_function_type)(void);

		std::unordered_map<std::string,void*> _loadedLibHandles;
    public:
		LinuxLibraryLoader():
			AbstractLibraryLoader()
    	{

		}
        virtual ~LinuxLibraryLoader()
        {
        	//dlclose(lib_handle);
        }

        virtual void loadLibrary(std::string file)
        {
        	if (_loadedLibHandles.find(file)==_loadedLibHandles.end())
        	{
				void* lib_handle;
				char *error;
				lib_handle = dlopen(file.c_str(), RTLD_LAZY);
				if (!lib_handle)
				{
					throw std::string(dlerror());
				}
				_loadedLibHandles[file]=lib_handle;
				init_function_type fn = (init_function_type)dlsym(lib_handle, "initialize");
				if ((error = dlerror()) != NULL)
				{
					throw std::string(dlerror());
				}
				(*fn)();
        	}
        }
};

#endif

