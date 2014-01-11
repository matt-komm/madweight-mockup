#include "Algorithm.hpp"

Algorithm::Algorithm(Configuration conf):
    Job(conf)
{
}

void Algorithm::addExternalVariable(Variable* var)
{
	_externalVariables.push_back(var);
}

Algorithm::~Algorithm()
{
}

