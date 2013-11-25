#include "VAMPIntegrator.hpp"
#include <cmath>
VAMPIntegrator::VAMPIntegrator(std::string name):
    Algorithm(name)
{
}

VAMPIntegrator::~VAMPIntegrator()
{
}

void VAMPIntegrator::execute()
{
    int dim = 2;
    int iterations = 5000;
    integrate_(&dim,&iterations,func);
}

double func(double** xi, int* prc_index)
{

    //std::cout<<"func has been called: "<<std::endl;
    //std::cout<<"\t xi[0] = "<<(*xi)[0]<<std::endl;
    //std::cout<<"\t xi[1] = "<<(*xi)[1]<<std::endl;
    //std::cout<<"\t prc_index = "<<*prc_index<<std::endl;
    //std::cout<<"\t weights[0] = "<<*weights[0]<<std::endl;
    //std::cout<<"\t channel = "<<*channel<<std::endl;
    UNUSED(prc_index);
    return exp (sin((*xi)[0]*(*xi)[1]*10)+1);
}

