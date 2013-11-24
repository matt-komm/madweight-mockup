#include "JobFactory.hpp"

JobFactory::JobFactory()
{
}

JobFactory::~JobFactory()
{
}

JobFactory* JobFactory::getInstance()
{
    static JobFactory jobFactory;
    return &jobFactory;
}

void JobFactory::registerJob(Job* job)
{
    _jobs.push_back(job);
}

void JobFactory::executeAll()
{
    for (unsigned int ijob=0; ijob<_jobs.size();++ijob)
    {
        if (_jobs[ijob]->isEnabled())
        {
            _jobs[ijob]->execute();
        }
    }
}
