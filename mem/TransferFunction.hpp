#ifndef __TRANSFERFUNCTION_H__
#define __TRANSFERFUNCTION_H__

#include "Module.hpp"
#include "Scalar.hpp"
#include "Configuration.hpp"

class TransferFunction:
    public Module
{
    protected:
		const Scalar* _inputME;
		const Scalar* _inputReco;
		Scalar* _weight;
    public:
        TransferFunction(Configuration config);
        ~TransferFunction();

        virtual void execute();
};

#endif

