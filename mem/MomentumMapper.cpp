#include "MomentumMapper.hpp"

MomentumMapper::MomentumMapper(Configuration config):
	Module(config)
{
	std::string varname = config.get("variableName");
}

MomentumMapper::~MomentumMapper()
{
}

void MomentumMapper::execute()
{

}
