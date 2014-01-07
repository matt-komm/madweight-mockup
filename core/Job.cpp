#include "Job.hpp"
#include "defs.hpp"

Job::Job(Configuration conf):
    _enable(true)
{
	UNUSED(conf)
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
