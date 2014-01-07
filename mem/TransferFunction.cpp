#include "TransferFunction.hpp"
#include <cmath>

TransferFunction::TransferFunction(Configuration config):
    Module(config)
{
	std::string inputMEName = config.get<std::string>("inputME");
	std::string inputRecoName = config.get<std::string>("inputReco");
	std::string outputVariableName = "weight";
	if (config.exists("output"))
	{
		outputVariableName = config.get<std::string>("output");
	}
	_inputME=getVariable<Scalar>(inputMEName);
	_inputReco=getVariable<Scalar>(inputRecoName);
	_weight=createVariable<Scalar>(outputVariableName);
}

TransferFunction::~TransferFunction()
{
}

void TransferFunction::execute()
{
	_weight->value()=exp(-pow(_inputME->value()-_inputReco->value(),2));
}
