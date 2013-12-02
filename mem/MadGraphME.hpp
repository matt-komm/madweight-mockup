#ifndef __MADGRAPHME_H__
#define __MADGRAPHME_H__

#include "MatrixElement.hpp"
#include "Configuration.hpp"
#include "Scalar.hpp"
#include "LorentzVector.hpp"

#include <iostream>

//class needs to be header only in order to generate the code during compilation
template<class ME>
class MadGraphME:
    public MatrixElement
{
    protected:
        ME* _me;
        std::vector<const LorentzVector*> _momenta;
        std::vector<double*> _mlist;
        Scalar* _output;

    public:
        MadGraphME(Configuration config):
            MatrixElement(config)        {
            _me=new ME();
            _me->initProc("param_card.dat");


            _output=createVariable<Scalar>("weight");


            for (int iexternal = 0; iexternal < _me->nexternal; ++iexternal)
            {
            	char name[15];
            	sprintf(name,"external_%u",iexternal+1);
            	_momenta.push_back(getVariable<LorentzVector>(name));
            }

        }

        int getNExternal()
        {
            return _me->nexternal;
        }

        ~MadGraphME()
        {
        }

        virtual void execute()
        {

            //_me->setMomenta
            _me->sigmaKin();
            const double* matrix_elements = _me->getMatrixElements();
            _output->value()=*matrix_elements;
        }
};

#endif


