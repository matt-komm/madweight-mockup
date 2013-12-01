#include "MomentumMapper.hpp"

MomentumMapper::MomentumMapper(Configuration config):
	Module(config)
{
	//std::cout<<"inputName="<<config.get("inputName")<<std::endl;
	//std::cout<<"inputName="<<_inputVarName;
	//std::cout<<config.get("outputName").value<std::string>()<<std::endl;
	//_mapping = config.get<std::string>("mapping");

	//_outputVector=createVariable<LorentzVector>("outputName");



}

MomentumMapper::~MomentumMapper()
{
}

void MomentumMapper::execute()
{

}
