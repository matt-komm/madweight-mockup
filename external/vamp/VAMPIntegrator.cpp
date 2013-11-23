#include "VAMPIntegrator.hpp"

VAMPIntegrator::VAMPIntegrator()
{
}

VAMPIntegrator::~VAMPIntegrator()
{
}

void VAMPIntegrator::execute()
{
    int i = 100;
    integrate_(&i,func);
}

void func(int* i)
{
    std::cout<<*i<<std::endl;
}


