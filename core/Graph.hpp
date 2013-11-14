#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "Node.hpp"


class Graph
{
    protected:
        Graph();
        virtual void addNode(Node* node);
    public:
        virtual ~Graph();
        static Graph* createFromNode(Node* node);
};

#endif

