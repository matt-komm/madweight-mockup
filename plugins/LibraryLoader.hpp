#ifndef __LIBRARYLOADER_H__
#define __LIBRARYLOADER_H__

#include <string>

class AbstractLibraryLoader
{
    protected:
    public:
		AbstractLibraryLoader()
    	{

    	}
        virtual ~AbstractLibraryLoader()
        {

        }

        virtual void loadLibrary(std::string file) = 0;
};

template<class LIBLOADER>
class LibraryLoaderInterface:
	public AbstractLibraryLoader
{
	public:
		LIBLOADER _libLoader;
		LibraryLoaderInterface():
			_libLoader()
		{

		}
		virtual ~LibraryLoaderInterface()
		{

		}

		virtual void loadLibrary(std::string file)
		{
			_libLoader.loadLibrary(file);
		}
};

//TODO: add cmake macro to add define statements with 'add_definition' to recognize the platform correctly
#ifndef WIN32
#define LIBLOADERFOUND
class LinuxLibraryLoader;
typedef LibraryLoaderInterface<LinuxLibraryLoader> LibraryLoader;
#endif

#ifndef LIBLOADERFOUND
#error "no suited library loader found or system not regonized"
#endif

#endif

