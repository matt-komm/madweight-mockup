#ifndef __JOB_H__
#define __JOB_H__

class Job
{
    protected:
    public:
        Job();
        ~Job();
        virtual void execute()=0;
};

#endif

