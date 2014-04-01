#ifndef __LORENTZVECTOR_H__
#define __LORENTZVECTOR_H__

#include <iostream>

#include "Variable.hpp"
#include "NVector.hpp"

class LorentzVector:
    public NVector
{
	protected:
		double& _px,_py,_pz,_e; //convenience

    public:
        LorentzVector(std::string name, Node* owner);
        virtual ~LorentzVector();

        virtual Variable* clone(Node* owner) const;


        virtual OpVariableInterface* createMultiplication(std::string name, Node* owner, const Variable* variable) const;

        virtual Variable::TYPE getType() const
        {
            return Variable::LORENTZVECTOR;
        }

        virtual void setPtEtaPhiMass(double pt, double eta, double phi, double mass);

};

void multiply(Scalar* target, const LorentzVector* var1, const LorentzVector* var2);


#endif

