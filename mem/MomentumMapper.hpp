#ifndef __MOMENTUMMAPPER_H__
#define __MOMENTUMMAPPER_H__

#include "Module.hpp"
#include "Scalar.hpp"
#include "LorentzVector.hpp"

#include "Configuration.hpp"

class MomentumMapper:
	public Module
{
    protected:
    public:
		MomentumMapper(Configuration config);
        virtual ~MomentumMapper();
        virtual void execute();
};

#endif

