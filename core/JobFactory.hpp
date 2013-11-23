#ifndef __JOBFACTORY_H__
#define __JOBFACTORY_H__

class JobFactory
{
    protected:
        JobFactory();
    public:
        static JobFactory* getInstance();
        ~JobFactory();
};

#endif

