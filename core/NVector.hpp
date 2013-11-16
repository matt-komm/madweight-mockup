#ifndef __NVECTOR_H__
#define __NVECTOR_H__

#include "Scalar.hpp"

class Node;

class NVector:
    public Variable
{
    protected:
        unsigned int _size;
        double** _values;

    public:
        NVector(std::string name, Node* owner);
        virtual ~NVector();

        virtual Variable* clone(Node* owner);

        virtual void setSize(unsigned int size);
        virtual const unsigned int size() const;
        virtual const double& value(const unsigned int index=0) const;
        virtual double& value(const unsigned int index=0);

        virtual OpVariableInterface* createMultiplication(std::string name, Node* owner, const Variable* variable) const;

        virtual const Variable::TYPE getType() const
        {
            return Variable::NVECTOR;
        }

};

void multiply(NVector* target, const NVector* var1, const Scalar* var2);
void multiply(Scalar* target, const NVector* var1, const NVector* var2);


#endif

