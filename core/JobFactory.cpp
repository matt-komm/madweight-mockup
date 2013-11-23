#include "JobFactory.hpp"

JobFactory::JobFactory()
{
}

JobFactory::~JobFactory()
{
}

JobFactory* JobFactory::getInstance()
{
    static JobFactory jobFactory;
    return &jobFactory;
}
