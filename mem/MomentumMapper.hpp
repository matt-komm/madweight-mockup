#ifndef __MOMENTUMMAPPER_H__
#define __MOMENTUMMAPPER_H__

#include "Module.hpp"
#include "Scalar.hpp"
#include "LorentzVector.hpp"
#include "Configuration.hpp"

#include <map>

class MomentumMapper:
	public Module
{
    protected:
		std::string _inputVarName;
		std::string _outputVarName;

		enum MappingType
		{
			PTETAPHI
		};
		MappingType _mapping;

		LorentzVector* _outputVector;
		std::map<std::string, const Scalar*> _inputMap;
    public:
		MomentumMapper(Configuration config);
        virtual ~MomentumMapper();
        virtual void execute();
};

#endif

