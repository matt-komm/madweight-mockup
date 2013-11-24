#ifndef __ALGORITHM_H__
#define __ALGORITHM_H__

#include "Node.hpp"
#include "Job.hpp"

#include <string>
#include <unordered_map>

class Algorithm:
    public Job
{
    protected:
    public:
        Algorithm(std::string name);
        virtual ~Algorithm();
};

#endif

