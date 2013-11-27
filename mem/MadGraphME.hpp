#ifndef __MADGRAPHME_H__
#define __MADGRAPHME_H__

#include "MatrixElement.hpp"
#include "Configuration.hpp"
#include "Scalar.hpp"

#include <iostream>

//class needs to be header only in order to generate the code during compilation
template<class ME>
class MadGraphME:
    public MatrixElement
{
    protected:
        ME* _me;
        Variable** _momenta;
        std::vector<double*> _mlist;
        std::vector<std::string> _particleNames;
        Scalar* _output;

    public:
        MadGraphME(Configuration config, std::vector<std::string> particleNames):
            MatrixElement(config),
            _particleNames(particleNames)
        {
            _me=new ME();
            _me->initProc("param_card.dat");
            _momenta=new Variable*[_me->nexternal];

            _output=createVariable<Scalar>("weight");
            if (_particleNames.size()!=_me->nexternal)
            {
            	throw std::string("provided list of particle names do not match the ME");
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


