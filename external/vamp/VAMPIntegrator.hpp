#ifndef __VAMPINTEGRATOR_H__
#define __VAMPINTEGRATOR_H__

#include "defs.hpp"
#include "Algorithm.hpp"

#include <iostream>

extern "C" 
{
    void integrate_(
        int *,
        int *,

        double (*fct)(double**, int*)
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

double func(double** xi, int* prc_index);

#endif

