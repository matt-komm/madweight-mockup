#include "Job.hpp"

Job::Job(Configuration conf):
    _enable(true)
{
    JobFactory::getInstance()->registerJob(this);
}

Job::~Job()
{
}

void Job::enable(bool enabled)
{
    _enable=enabled;
}

bool Job::isEnabled() const
{
    return _enable;
}
