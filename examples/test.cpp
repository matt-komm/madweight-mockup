#include "MatrixElement.hpp"
#include "Configuration.hpp"
#include "MadGraphME.hpp"
#include "MomentumMapper.hpp"
#include "P0_Sigma_sm_gg_gg_qcd_2j.h"

int main()
{
    Configuration meConfig = Configuration::createEmpty();
    meConfig.insert("name","test");

    MadGraphME<P0_Sigma_sm_gg_gg_qcd_2j> me=MadGraphME<P0_Sigma_sm_gg_gg_qcd_2j>(meConfig);

    Configuration momentumConfig = Configuration::createEmpty();
    momentumConfig.insert("inputName","muon");
    momentumConfig.insert("outputName","external_1");

    MomentumMapper mapper = MomentumMapper(momentumConfig);
    //std::cout<<"number of external particles: "<<me->getNExternal()<<std::endl;
    return 0;
}


