#ifndef __LIBRARYLOADER_H__
#define __LIBRARYLOADER_H__

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

#endif

