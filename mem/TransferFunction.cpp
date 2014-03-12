#include "TransferFunction.hpp"
#include <cmath>

TransferFunction::TransferFunction(Configuration config):
    Module(config)
{
	std::string inputMEName = config.get("inputME").value<std::string>();
	std::string inputRecoName = config.get("inputReco").value<std::string>();
	std::string outputVariableName = "weight";
	if (config.exists("output"))
	{
		outputVariableName = config.get("output").value<std::string>();
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
