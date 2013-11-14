#ifndef __VARIABLEARRAY_H__
#define __VARIABLEARRAY_H__

#include <vector>

#include "Variable.hpp"
#include "Node.hpp"

template<class VARIABLE>
class VariableArray:
    public Variable
{
    protected:
        std::vector<VARIABLE*> _array;
    public:
        VariableArray(std::string name, Node* owner);
        ~VariableArray();
};

#endif

