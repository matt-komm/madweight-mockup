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

Variable* Scalar::multiply(std::string name, Node* owner, Variable* var)
{
    if (var->getType()==Variable::SCALAR)
    {
        Scalar* result = new Scalar(name,owner);
        multiply(result,var);
        return result;
    }
    else
    {
        return 0;
    }
}


void Scalar::multiply(Variable* target, Variable* input)
{
    if (input->getType()==Variable::SCALAR && target->getType()==Variable::SCALAR)
    {
        target->value()=value()*input->value();
    }
}

Variable* Scalar::add(std::string name, Node* owner, Variable* var)
{
    if (var->getType()==Variable::SCALAR)
    {
        Scalar* result = new Scalar(name,owner);
        add(result,var);
        return result;
    }
    else
    {
        return 0;
    }
}


void Scalar::add(Variable* target, Variable* input)
{
    if (input->getType()==Variable::SCALAR && target->getType()==Variable::SCALAR)
    {
        target->value()=value()+input->value();
    }
}

std::ostream& operator<<(std::ostream& os, const Scalar* scalar)
{
    os<<"class = Scalar: { value="<<scalar->value()<<"}";
    return os;
}
