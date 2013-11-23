#ifndef __TRANSFERFUNCTION_H__
#define __TRANSFERFUNCTION_H__

#include "Module.hpp"
#include "Configuration.hpp"

class TransferFunction:
    public Module
{
    protected:
    public:
        TransferFunction(Configuration config);
        ~TransferFunction();

        virtual void execute();
};

#endif

