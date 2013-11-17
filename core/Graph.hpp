#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "Node.hpp"
#include <unordered_map>
#include <string>
#include <vector>

class Graph
{
    struct Edge
    {
        std::string name;
        Node* target;
    };

    struct Leaf
    {
        std::vector<Edge*> out;
        Node* owner;
        std::vector<Edge*> in;
    };

    protected:
        std::vector<Leaf*> _leafs;
        std::vector<Node*> _sortedNodes;
    public:
        Graph();
        virtual ~Graph();
        void sort();
        std::vector<Node*> getSortedList();
        void executeAll();
        virtual void addNode(Node* node);
        static Graph* createFromNode(Node* node);
};

#endif

