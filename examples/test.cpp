#include "MatrixElement.hpp"
#include "Configuration.hpp"
#include "MadGraphME.hpp"
#include "P0_Sigma_sm_gg_gg_qcd_2j.h"
int main()
{
    Configuration config = Configuration::createEmpty();
    config.insert("name","test");
    //name here the external particle names and their masses
    //MadGraphME<P0_Sigma_sm_gg_gg_qcd_2j>* me=MadGraphME<P0_Sigma_sm_gg_gg_qcd_2j>::create(config);
    //std::cout<<"number of external particles: "<<me->getNExternal()<<std::endl;
    return 0;
}


