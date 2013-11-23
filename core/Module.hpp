#ifndef __MODULE_H__
#define __MODULE_H__

#include "Node.hpp"
#include "Configuration.hpp"

class Module:
    public Node
{
    protected:
    public:
        Module(Configuration config);
        ~Module();

        virtual void execute() = 0;
};

#endif

