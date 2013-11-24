#ifndef __JOB_H__
#define __JOB_H__

#include "JobFactory.hpp"

#include <string>

class Job
{
    protected:
        std::string _name;
        bool _enable;
    public:
        Job(std::string name);
        ~Job();
        virtual void execute()=0;
        void enable(bool enabled);
        bool isEnabled() const;
};

#endif

