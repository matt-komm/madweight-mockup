#ifndef __ALGORITHM_H__
#define __ALGORITHM_H__

#include "Node.hpp"
#include "Variable.hpp"
#include "Job.hpp"
#include "Configuration.hpp"
#include "Graph.hpp"

#include <string>

class Algorithm:
    public Job
{
    protected:
		std::map<std::string,Graph*> _graphMap;
    public:
        Algorithm(Configuration conf);
        void addGraph(std::string name, Graph& graph);
        virtual ~Algorithm();
};

#endif

