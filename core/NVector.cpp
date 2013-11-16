#include "NVector.hpp"

NVector::NVector(std::string name, Node* owner):
    Variable(name,owner),
    _size(1)
{
    _values=new double*[1];
    _values[0]=new double(0);
}

NVector::~NVector()
{
    for (int i=0; i<_size;++i)
    {
        delete _values[i];
    }
    delete _values;
}

Variable* NVector::clone(Node* owner)
{
    NVector* clone = new NVector(_name,owner);
    clone->setSize(this->size());
    for (int i = 0; i<_size; ++i)
    {
        clone->value(i)=*_values[i];
    }
    return clone;
}

void NVector::setSize(unsigned int size)
{
    //delete before reallocating new memory
    for (int i=0;i<_size; ++i)
    {
        delete _values[i];
    }
    _size=size;
    _values=new double*[size];
    for (int i=0;i<_size;++i)
    {
        _values[i] = new double(0);
    }
}

const unsigned int NVector::size() const
{
    return _size;
}

const double& NVector::value(const unsigned int index) const
{
    return *_values[index];
}

double& NVector::value(const unsigned int index)
{
    return *_values[index];
}

OpVariableInterface* NVector::createMultiplication(std::string name, Node* owner, const Variable* variable) const
{
    if (_size!=variable->size())
    {
        throw std::string("createMultiplication: variable do not have the same size: "+_name+", "+variable->getName());
    }
    if (variable->getType()==Variable::SCALAR)
    {
        NVector* target = new NVector(name,owner);
        target->setSize(_size);
        OpVariable<NVector,NVector,Scalar>* opVariable = new OpVariable<NVector,NVector,Scalar>(multiply,target,this,dynamic_cast<const Scalar*>(variable));
        return opVariable;
    }
    else if (variable->getType()==Variable::NVECTOR)
    {
        Scalar* target = new Scalar(name,owner);
        OpVariable<Scalar,NVector,NVector>* opVariable = new OpVariable<Scalar,NVector,NVector>(multiply,target,this,dynamic_cast<const NVector*>(variable));
        return opVariable;
    }
}

void multiply(NVector* target, const NVector* var1, const Scalar* var2)
{
    for (unsigned int i = 0; i < target->size(); ++i )
    {
        target->value(i)=var1->value(i)*var2->value();
    }
}

void multiply(Scalar* target, const NVector* var1, const NVector* var2)
{
    target->value()=0.0;
    for (unsigned int i = 0; i < target->size(); ++i )
    {
        target->value()+=var1->value(i)*var2->value(i);
    }
}


