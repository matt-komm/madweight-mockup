#include "Algorithm.hpp"

#include "Variable.hpp"

Algorithm::Algorithm(Configuration conf):
    Job(conf),
    _graph(0),
    _node(0)
{
}

void Algorithm::setGraph(Graph& graph)
{
	if (_node)
	{
		delete _node;
	}
	_node = new ConstantNode();
	_graph=&graph;
	_graph->createExternals(_node);
}

void Algorithm::execute()
{
}

Algorithm::~Algorithm()
{
	if (_node)
	{
		delete _node;
	}
}

