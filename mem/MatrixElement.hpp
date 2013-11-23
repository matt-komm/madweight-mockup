#ifndef __MATRIXELEMENT_H__
#define __MATRIXELEMENT_H__

#include "MatrixElement.hpp"
#include "Module.hpp"
#include "Configuration.hpp"

class MatrixElement:
    public Module
{
    protected:
    public:
        MatrixElement(Configuration config);
        ~MatrixElement();

        virtual void execute();
};

#endif

