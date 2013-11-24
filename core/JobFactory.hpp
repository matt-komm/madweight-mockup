#ifndef __JOBFACTORY_H__
#define __JOBFACTORY_H__


#include "Job.hpp"
class Job;
#include <vector>

class JobFactory
{
    protected:
        JobFactory();
        std::vector<Job*> _jobs;
    public:
        static JobFactory* getInstance();
        ~JobFactory();
        void registerJob(Job* job);

        void executeAll();
};

#endif

