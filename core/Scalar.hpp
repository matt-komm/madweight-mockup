#ifndef __SCALAR_H__
#define __SCALAR_H__

#include <iostream>

#include "Variable.hpp"

class Scalar:
    public Variable
{
    protected:
        double* _value;

    public:
        Scalar(std::string name, Node* owner);
        virtual ~Scalar();

        virtual Variable* clone(Node* owner) const;

        virtual void setSize(unsigned int size);
        virtual unsigned int size() const;
        virtual const double& value(const unsigned int index=0) const;
        virtual double& value(const unsigned int index=0);

        virtual OpVariableInterface* createMultiplication(std::string name, Node* owner, const Variable* variable) const;

        virtual Variable::TYPE getType() const
        {
            return Variable::SCALAR;
        }

};

void multiply(Scalar* target, const Scalar* var1, const Scalar* var2);


#endif

