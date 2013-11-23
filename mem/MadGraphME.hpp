#ifndef __MADGRAPHME_H__
#define __MADGRAPHME_H__

#include "MatrixElement.hpp"
#include "Configuration.hpp"

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
    public:
        MadGraphME(Configuration config):
            MatrixElement(config)
        {
            try
            {
                _me=new ME();
                _me->initProc("param_card.dat");
                _momenta=new Variable*[_me->nexternal];

                for (int i = 0; i< _me->nexternal; ++i)
                {
                    //_mlist
                    //_momenta[i]=getVariable<Scalar>("name");
                }
            } catch (const char* msg) {
                std::cout<<msg<<std::endl;
            }
        }
        ~MadGraphME()
        {

        }

        virtual void execute()
        {

            //_me->setMomenta
            _me->sigmaKin();
            const double* matrix_elements = _me->getMatrixElements();
        }
};

#endif

