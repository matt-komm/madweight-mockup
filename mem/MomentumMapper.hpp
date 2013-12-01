#ifndef __MOMENTUMMAPPER_H__
#define __MOMENTUMMAPPER_H__

#include "Module.hpp"
#include "Scalar.hpp"
#include "LorentzVector.hpp"
#include "Configuration.hpp"

#include <unordered_map>

class MomentumMapper:
	public Module
{
    protected:
		std::string _inputVarName;
		std::string _outputVarName;
		std::string _mapping;

		//LorentzVector* _outputVector;

		//std::unordered_map<std::string, Scalar*> _inputMap;
    public:
		MomentumMapper(Configuration config);
        virtual ~MomentumMapper();
        virtual void execute();
};

#endif

