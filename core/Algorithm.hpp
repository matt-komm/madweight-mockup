#ifndef __ALGORITHM_H__
#define __ALGORITHM_H__

#include "Node.hpp"

#include "Job.hpp"
#include "Configuration.hpp"
#include "Graph.hpp"

#include <string>

class Algorithm:
    public Job
{
    protected:
		Graph* _graph;
		ConstantNode* _node;
    public:
        Algorithm(Configuration conf);
        virtual void execute();
        inline Node* getNode()
        {
        	return _node;
        }
        void setGraph(Graph& graph);
        virtual ~Algorithm();
};

#endif

