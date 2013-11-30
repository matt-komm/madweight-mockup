#ifndef __LORENTZVECTOR_H__
#define __LORENTZVECTOR_H__

#include <iostream>

#include "Variable.hpp"
#include "NVector.hpp"

class LorentzVector:
    public NVector
{

    public:
        LorentzVector(std::string name, Node* owner);
        virtual ~LorentzVector();

        virtual Variable* clone(Node* owner);


        virtual OpVariableInterface* createMultiplication(std::string name, Node* owner, const Variable* variable) const;

        virtual Variable::TYPE getType() const
        {
            return Variable::LORENTZVECTOR;
        }

};

void multiply(Scalar* target, const LorentzVector* var1, const LorentzVector* var2);


#endif

