#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "Node.hpp"
#include <graphviz/gvc.h>
#include <graphviz/graph.h>


class Graph
{
    protected:
        Graph();
        GVC_t* gvc;
        Agraph_t* g;
        std::vector<Agnode_t*> nodes;
        void addNode(Node* node);
    public:
        ~Graph();

        static Graph* createFromNode(Node* node);

        void render(std::string filename);
};

#endif

