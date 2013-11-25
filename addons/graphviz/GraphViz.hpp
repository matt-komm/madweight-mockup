#ifndef __GRAPHVIZ_H__
#define __GRAPHVIZ_H__

#include "Node.hpp"
#include "Graph.hpp"

#include <graphviz/gvc.h>
#include <graphviz/graph.h>

char* strtochar(std::string s)
{
    char* c = new char[s.length()+1];
    //strcpy(c,s.c_str());
    return c;
}

class GraphViz:
    public Graph
{
    protected:
            struct GraphVizEdge:Edge
            {

            };

            struct GraphVizLeaf:Leaf
            {
                Agnode_t* gnode;
            };

            GVC_t* gvc;
            Agraph_t* g;
            std::vector<Agnode_t*> nodes;
            std::string createNodeRepresentation(Node* node);
        public:
            GraphViz();
            ~GraphViz();

            virtual void addNode(Node* node);
            virtual void render(std::string filename);
};

#endif

