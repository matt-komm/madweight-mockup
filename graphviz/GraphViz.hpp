#ifndef __GRAPHVIZ_H__
#define __GRAPHVIZ_H__

#include "Node.hpp"

#include <graphviz/gvc.h>
#include <graphviz/graph.h>

class GraphViz
{
    protected:
            GraphViz();
            GVC_t* gvc;
            Agraph_t* g;
            std::vector<Agnode_t*> nodes;
            void addNode(Node* node);
        public:
            ~GraphViz();

            static GraphViz* createFromNode(Node* node);

            void render(std::string filename);
};

#endif

