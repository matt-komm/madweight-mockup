#include "LorentzVector.hpp"
#include <iostream>
#include <cmath>

LorentzVector::LorentzVector(std::string name, Node* owner):
    NVector(name,owner,4),
    _px(*_values[1]),
	_py(*_values[2]),
	_pz(*_values[3]),
	_e(*_values[0])
{
}

LorentzVector::~LorentzVector()
{
    //delete _value;
}

Variable* LorentzVector::clone(Node* owner) const
{
	LorentzVector* lorentzVector = new LorentzVector(_name,owner);
	lorentzVector->value(0)=this->value(0);
	lorentzVector->value(1)=this->value(1);
	lorentzVector->value(2)=this->value(2);
	lorentzVector->value(3)=this->value(3);
    //std::cout<<scalar<<" is clone of "<<this<<std::endl;
    return lorentzVector;
}

void LorentzVector::setPtEtaPhiMass(double pt, double eta, double phi, double mass)
{
	_px = pt*cos(phi);
	_py = pt*sin(phi);
	_pz = pt*sinh(eta);
	_e = sqrt(_px*_px+_py*_py+_pz*_pz+mass*mass);
}

OpVariableInterface* LorentzVector::createMultiplication(std::string name, Node* owner, const Variable* variable) const
{

    if (this->getType()==Variable::LORENTZVECTOR && variable->getType()==Variable::LORENTZVECTOR)
    {
        Scalar* target = new Scalar(name,owner);
        OpVariable<Scalar,LorentzVector,LorentzVector>* opVariable = new OpVariable<Scalar,LorentzVector,LorentzVector>(multiply,target,this,dynamic_cast<const LorentzVector*>(variable));
        return opVariable;
    }
    return 0;
}


void multiply(Scalar* target, const LorentzVector* var1, const LorentzVector* var2)
{
    target->value()=var1->value(0)*var2->value(0);
    target->value()-=var1->value(1)*var2->value(1);
    target->value()-=var1->value(2)*var2->value(2);
    target->value()-=var1->value(3)*var2->value(3);
}
