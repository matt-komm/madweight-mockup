#ifndef __JOB_H__
#define __JOB_H__

#include "JobFactory.hpp"
#include "Configuration.hpp"

#include <string>

class Job
{
    protected:
        bool _enable;
    public:
        Job(Configuration conf);
        ~Job();
        virtual void execute()=0;
        void enable(bool enabled);
        bool isEnabled() const;
};

#endif

