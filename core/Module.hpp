#ifndef __MODULE_H__
#define __MODULE_H__

#include "Node.hpp"
#include "Configuration.hpp"

class Module:
    public Node
{
    protected:
        Configuration _config;
    public:
        Module(Configuration config);
        virtual ~Module();

        virtual void execute() = 0;
};

#endif

