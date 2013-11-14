#include "VariableArray.hpp"
#include "Scalar.hpp"

template<class VARIABLE>
VariableArray<VARIABLE>::VariableArray(std::string name, Node* owner):
    Variable(name,owner)
{
}

template<class VARIABLE>
VariableArray<VARIABLE>::~VariableArray()
{
}

template class VariableArray<Scalar>;
