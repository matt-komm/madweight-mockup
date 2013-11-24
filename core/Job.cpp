#include "Job.hpp"

Job::Job(std::string name):
    _name(name),
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
