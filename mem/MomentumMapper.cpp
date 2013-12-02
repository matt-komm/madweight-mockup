#include "MomentumMapper.hpp"

MomentumMapper::MomentumMapper(Configuration config):
	Module(config)
{
	_inputVarName=config.get<std::string>("inputName");
	_outputVarName=config.get<std::string>("outputName");

	std::string mappingName = config.get<std::string>("mapping");
	if (mappingName=="PtEtaPhi")
	{
		_mapping=PTETAPHI;
	}
	else
	{
		throw std::string("mapping name not regonized!");
	}

	_outputVector=createVariable<LorentzVector>(_outputVarName);

	if (_mapping==PTETAPHI)
	{
		_inputMap["pt"]=getVariable<Scalar>(_inputVarName+"_pt");
		_inputMap["eta"]=getVariable<Scalar>(_inputVarName+"_eta");
		_inputMap["phi"]=getVariable<Scalar>(_inputVarName+"_phi");
		_inputMap["mass"]=getVariable<Scalar>(_inputVarName+"_mass");
	}


}

MomentumMapper::~MomentumMapper()
{
}

void MomentumMapper::execute()
{
	if (_mapping==PTETAPHI)
	{
		_outputVector->setPtEtaPhiMass(
			_inputMap["pt"]->value(),
			_inputMap["eta"]->value(),
			_inputMap["phi"]->value(),
			_inputMap["mass"]->value()
		);
	}
}
