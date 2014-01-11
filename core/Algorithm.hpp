#ifndef __ALGORITHM_H__
#define __ALGORITHM_H__

#include "Node.hpp"
#include "Variable.hpp"
#include "Job.hpp"
#include "Configuration.hpp"

#include <string>
#include <unordered_map>

class Algorithm:
    public Job
{
    protected:
		std::vector<Variable*> _externalVariables;
    public:
        Algorithm(Configuration conf);
        virtual ~Algorithm();

        void addExternalVariable(Variable* var);
};

#endif

