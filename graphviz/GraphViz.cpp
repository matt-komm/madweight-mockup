#include "GraphViz.hpp"

//#define WITH_CGRAPH
#include <iostream>

GraphViz::GraphViz():
    Graph()
{
    /*
    Agraph_t* g =  agopen("G", Agdirected, NULL);
    std::vector<Agnode_t*> nodes;
    for (int i =0; i<10;++i)
    {
        char* name = new char[10];
        sprintf(name,"node %i",i);
        Agnode_t* node = agnode(g, name,NULL);
        nodes.push_back(node);
    }
    for (int i =0; i<5; ++i)
    {
        int n1 = rand() % nodes.size();
        int n2 = rand() % nodes.size();
        agedge(g, nodes[n1], nodes[n2],"e",0);
    }
    FILE* f = fopen ("myfile.txt" , "w");
    agwrite(g,f);
    */
    gvc = gvContext();
    aginit();

    g = agopen("G", AGDIGRAPH);
    /*
    for (int i =0; i<10;++i)
    {
        char* name = new char[10];
        sprintf(name,"node %i",i);
        char* label = new char[100];
        sprintf(label,"{ { <ain> a  | <bin> b} |{ node %i } | {<aout> a| <bout> b}}",i);
        Agnode_t* node = agnode(g, name);
        //agattr(node,"color","red");
        agattr(node,"shape","record");

        agset(node,"label",label);

        nodes.push_back(node);
    }

    for (int i =0; i<10; ++i)
    {
        int n1 = rand() % nodes.size();
        int n2 = rand() % nodes.size();
        Agedge_t* edge = agedge(g, nodes[n1], nodes[n2]);
        agattr(edge,"headport","ain:n");
        agattr(edge,"tailport","aout:s");
        if (rand()%2==1)
        {
            agset(edge,"headport","bin:n");
        }

        if (rand()%2==1)
        {
            agset(edge,"tailport","bout:s");
        }
    }
    */
    /*
    gvLayout (gvc, g, "dot");
    //point pos = agget(nodes[0],"point");
    //std::cout<<"pos:"<<pos<<std::endl;
    gvRenderFilename(gvc, g, "png", "graph.png");
    FILE* f = fopen ("myfile.txt" , "w");
    agwrite(g,f);
    gvFreeLayout(gvc, g);
    agclose (g);
    gvFreeContext(gvc);
    */
}

GraphViz::~GraphViz()
{
    gvFreeLayout(gvc, g);
    agclose (g);
    gvFreeContext(gvc);
}

void GraphViz::addNode(Node* node)
{
    //std::cout<<"adding node"<<std::endl;
    GraphVizLeaf* leaf = new GraphVizLeaf();
    Graph::_setupLeaf(leaf,node);
    char name[20];
    sprintf(name,"node %i",_leafs.size());
    leaf->gnode = agnode(g, name);
    agattr(leaf->gnode,"shape","record");
    std::string slabel=createNodeRepresentation(leaf->owner);
    char* label = new char[slabel.length()];
    sprintf(label,"%s",slabel.c_str());
    agset(leaf->gnode,"label",label);

    _leafs.push_back(leaf);
}

std::string GraphViz::createNodeRepresentation(Node* node)
{

    std::string inputLabels = "{";
    if (node->getInputSize()>0)
    {
        for (unsigned int i=0; i<node->getInputSize()-1; ++i)
        {
            //std::cout<<"for "<<i<<" | "<<node->getInputSize()<<std::endl;
            inputLabels+="<"+node->getInput(i)->getName()+"> "+node->getInput(i)->getName()+" |";
        }
        inputLabels+="<"+node->getInput(node->getInputSize()-1)->getName()+"> "+node->getInput(node->getInputSize()-1)->getName()+"}";
    }
    else
    {
        inputLabels+="empty }";
    }
    //std::cout<<"input: "<<inputLabels<<std::endl;
    std::string outputLabels = "{";

    if (node->getOutputSize()>0)
    {
        for (unsigned int i=0; i<node->getOutputSize()-1; ++i)
        {
            outputLabels+="<"+node->getOutput(i)->getName()+"> "+node->getOutput(i)->getName()+" |";
        }
        outputLabels+="<"+node->getOutput(node->getOutputSize()-1)->getName()+"> "+node->getOutput(node->getOutputSize()-1)->getName()+"}";
    }
    else
    {
        outputLabels+="empty }";
    }
    //std::cout<<"output: "<<outputLabels<<std::endl;

    return std::string("{ "+inputLabels+" | { node } | "+outputLabels+" }");
    /*
    char* name = new char[20];
    sprintf(name,"node %i",nodes.size());
    Agnode_t* graphviznode = agnode(g, name);
    //agattr(node,"color","red");
    agattr(graphviznode,"shape","record");
    agset(graphviznode,"label",label);
    nodes.push_back(graphviznode);
    */
}


void GraphViz::render(std::string filename)
{
    /*
    for (unsigned int i = 0; i< Graph::_leafs.size(); ++i)
    {
        Leaf* leaf = Graph::_leafs[i];
        char name[20];
        sprintf(name,"node %i",nodes.size());
        Agnode_t* graphviznode = agnode(g, name);
        agattr(graphviznode,"shape","record");
        std::string slabel=createNodeRepresentation(leaf->owner);
        char* label = new char[slabel.length()];
        sprintf(label,"%s",slabel.c_str());
        agset(graphviznode,"label",label);
        nodes.push_back(graphviznode);
    }
    for (unsigned int i = 0; i< Graph::_leafs.size(); ++i)
    {
        Leaf* leaf = Graph::_leafs[i];
        for (unsigned int j = 0; j<leaf->out.size(); ++j)
        {
            Edge* edge = leaf->out[j];
            for (unsigned int k = 0; k<_leafs.size(); ++k)
            {
                if (_leafs[k]->owner==edge->target)
                {
                    Agedge_t* gedge = agedge(g,nodes[i],nodes[k]);
                    //char* headport = new char[100];
                    //sprintf(headport,"%s:n",edge->name.c_str());
                    //char* tailport = new char[100];
                    //sprintf(tailport,"%s:s",_leafs[k]->in[0].c_str());
                    //agattr(gedge,"headport",headport);
                    //agattr(gedge,"tailport",tailport);
                }
            }
        }
    }
    */
    //agedge(g,nodes[0],nodes[1]);
    gvLayout (gvc, g, "dot");
    //point pos = agget(nodes[0],"point");
    //std::cout<<"pos:"<<pos<<std::endl;
    gvRenderFilename(gvc, g, "png", (filename+".png").c_str());
    FILE* f = fopen ((filename+".txt").c_str() , "w");
    agwrite(g,f);
    fclose(f);

}

