#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "Node.hpp"
#include <unordered_map>
#include <string>
#include <vector>

class Graph
{


    protected:

        struct Leaf;

        struct Edge
        {
            std::string name;
            Node* target;
            Leaf* leaf;
        };

        struct Leaf
        {
            std::vector<Edge*> out;
            Node* owner;
            std::vector<Edge*> in;
        };



        std::vector<Leaf*> _leafs;
        std::vector<Node*> _sortedNodes;
        virtual void _setupLeaf(Leaf* leaf, Node* node);
        Graph::Leaf* _findLeaf(Node* node);
    public:
        Graph();
        virtual ~Graph();
        virtual void sort();
        virtual std::vector<Node*> getSortedList();
        virtual void executeAll();
        virtual void addNode(Node* node);
};

#endif

