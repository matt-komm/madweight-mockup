#include "Graph.hpp"


Graph::Graph()
{


}

Graph::~Graph()
{

}

void Graph::addNode(Node* node)
{


}


Graph* Graph::createFromNode(Node* node)
{
    Graph* graph = new Graph();
    graph->addNode(node);
    return graph;
}
