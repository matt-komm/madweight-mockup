#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "Node.hpp"
#include <unordered_map>
#include <string>
#include <vector>

class Graph
{


    protected:

        class Leaf;

        class Edge
        {
        	public:
            std::string nameIn;
            std::string nameOut;
            Node* target;
            Leaf* leaf;
            Edge()
            {
            }
        };

        class Leaf
        {
        	public:
            std::vector<Edge*> out;
            Node* owner;
            std::vector<Edge*> in;
            Leaf()
            {
            }
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
        virtual void setupGraphConnections();
};

#endif

