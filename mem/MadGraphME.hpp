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

        MadGraphME(Configuration config):
            MatrixElement(config)
        {
            _me=new ME();
            _me->initProc("param_card.dat");
            _momenta=new Variable*[_me->nexternal];



            for (int i = 0; i< _me->nexternal; ++i)
            {
                _mlist.push_back(new double(0));
                //_momenta[i]=getVariable<Scalar>("name");
            }
        }
    public:
        static MadGraphME<ME>* create(Configuration config)
        {
            try
            {
                MadGraphME<ME>* madGraphME = new MadGraphME<ME>(config);
                return madGraphME;
            } catch (const char* msg) {
                std::cout<<msg<<std::endl;
            }
            return 0;
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
        }
};

#endif


