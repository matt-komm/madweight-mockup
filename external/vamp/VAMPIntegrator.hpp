#ifndef __VAMPINTEGRATOR_H__
#define __VAMPINTEGRATOR_H__

#include <iostream>

extern "C" 
{
    void integrate_(
        int *,
        void (*fct)(int*)
    );
}

class VAMPIntegrator
{
    protected:
    public:
        VAMPIntegrator();
        ~VAMPIntegrator();
        
        virtual void execute();
};

void func(int* i);

#endif

