#ifndef __ABSTRACTLIBRARYLOADER_H__
#define __ABSTRACTLIBRARYLOADER_H__

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

#endif
