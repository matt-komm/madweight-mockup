
#include "VAMPIntegrator.hpp"
#include "JobFactory.hpp"

int main()
{
    VAMPIntegrator integrator("integration");
    //integrator.execute();
    JobFactory::getInstance()->executeAll();
    return 0;
}
