#ifndef __VAMPINTEGRATOR_H__
#define __VAMPINTEGRATOR_H__

#include "Algorithm.hpp"

#include <iostream>

extern "C" 
{
    void integrate_(
        int *,
        void (*fct)(int*)
    );
}

class VAMPIntegrator:
    public Algorithm
{
    protected:
    public:
        VAMPIntegrator(std::string name);
        ~VAMPIntegrator();
        
        virtual void execute();
};

void func(int* i);

#endif

