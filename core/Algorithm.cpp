#include "Algorithm.hpp"

Algorithm::Algorithm(Configuration conf):
    Job(conf)
{
}

void Algorithm::addGraph(std::string name, Graph& graph)
{
	if (_graphMap.find(name)==_graphMap.end())
	{
		_graphMap[name]=&graph;
	}
	else
	{
		throw std::string("Graph with name '"+name+"' already registered in algorithm.");
	}
}

Algorithm::~Algorithm()
{
}

