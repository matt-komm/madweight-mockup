#include "MomentumMapper.hpp"

MomentumMapper::MomentumMapper(Configuration config):
	Module(config)
{
	_inputVarName = config.get<std::string>("inputName");
	_outputVarName = config.get<std::string>("outputName");
}

MomentumMapper::~MomentumMapper()
{
}

void MomentumMapper::execute()
{

}
