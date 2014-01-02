#ifndef __ALGORITHM_H__
#define __ALGORITHM_H__

#include "Node.hpp"
#include "Job.hpp"
#include "Configuration.hpp"

#include <string>
#include <unordered_map>

class Algorithm:
    public Job
{
    protected:
    public:
        Algorithm(Configuration conf);
        virtual ~Algorithm();
};

#endif

