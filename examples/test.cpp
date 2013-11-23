#include "MatrixElement.hpp"
#include "Configuration.hpp"
#include "MadGraphME.hpp"
#include "P0_Sigma_sm_gg_gg_qcd_2j.h"
int main()
{
    Configuration config;
    Configuration::GenericType name= Configuration::GenericType("test");
    config.insert("name","test");
    MadGraphME<P0_Sigma_sm_gg_gg_qcd_2j> me=MadGraphME<P0_Sigma_sm_gg_gg_qcd_2j>(config);
    return 0;
}


