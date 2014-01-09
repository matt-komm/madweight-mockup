#include "MatrixElement.hpp"
#include "Configuration.hpp"
#include "MadGraphME.hpp"
#include "MomentumMapper.hpp"
#include "GraphViz.hpp"
#include "P0_Sigma_sm_gg_gg_qcd_2j.h"

int main()
{

    Configuration meConfig = Configuration::createEmptyDict();
    meConfig.insertDictEntry("name","test");

    std::cout<<meConfig.get<std::string>("name")<<std::endl;
    MadGraphME<P0_Sigma_sm_gg_gg_qcd_2j> me=MadGraphME<P0_Sigma_sm_gg_gg_qcd_2j>(meConfig);

    /*
    Configuration momentumConfig = Configuration::createEmpty();
    momentumConfig.insert("inputName","muon");
    momentumConfig.insert("outputName","external_1");
    momentumConfig.insert("mapping","PtEtaPhi");

    MomentumMapper mapper = MomentumMapper(momentumConfig);
    me.connectInput(me.getInput<LorentzVector>("external_2"),mapper.getOutput<LorentzVector>("external_1"));
    me.connectInputAll(&mapper);
    */

    GraphViz* graph = new GraphViz();
    graph->addNode(&me);
    //graph->addNode(&mapper);
    graph->setupGraphConnections();
    graph->render("test");

    //graph->sort();
    //graph->executeAll();

    //std::cout<<"number of external particles: "<<me->getNExternal()<<std::endl;

    return 0;
}


