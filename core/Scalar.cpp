#include "Scalar.hpp"
#include <iostream>

Scalar::Scalar(std::string name, Node* owner):
    Variable(name,owner)

{
    _value = new double(0);
}

Scalar::~Scalar()
{
    delete _value;
}

Variable* Scalar::clone(Node* owner)
{
    Scalar* scalar = new Scalar(_name,owner);
    scalar->value()=this->value();
    return scalar;
}

unsigned int Scalar::size()
{
    return 1;
}

const double& Scalar::value(const unsigned int index) const
{
    return *_value;
}

double& Scalar::value(const unsigned int index)
{
    return *_value;
}

OpVariableInterface* Scalar::createMultiplication(std::string name, Node* owner, const Variable* variable) const
{

    if (this->getType()==Variable::SCALAR && variable->getType()==Variable::SCALAR)
    {
        Scalar* target = new Scalar(name,owner);
        OpVariable<Scalar,Scalar,Scalar>* opVariable = new OpVariable<Scalar,Scalar,Scalar>(multiply,target,this,dynamic_cast<const Scalar*>(variable));
        return opVariable;
    }
    return 0;
}


void multiply(Scalar* target, const Scalar* var1, const Scalar* var2)
{
    target->value()=var1->value()*var2->value();
}
