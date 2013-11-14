#ifndef __SCALAR_H__
#define __SCALAR_H__

#include <iostream>

#include "Variable.hpp"

class Scalar:
    public Variable,
    public Addable,
    public Multipliable
{
    protected:
        double* _value;

    public:
        Scalar(std::string name, Node* owner);
        virtual ~Scalar();

        virtual Variable* clone(Node* owner);

        virtual unsigned int size();
        virtual const double& value(const unsigned int index=0) const;
        virtual double& value(const unsigned int index=0);

        virtual Variable::TYPE getType()
        {
            return Variable::SCALAR;
        }

        virtual Variable* multiply(std::string name, Node* owner, Variable* var);
        virtual void multiply(Variable* target, Variable* input);

        virtual Variable* add(std::string name, Node* owner, Variable* var);
        virtual void add(Variable* target, Variable* input);
};

std::ostream& operator<<(std::ostream& os, const Scalar* scalar);

#endif

