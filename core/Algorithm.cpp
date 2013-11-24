#include "Algorithm.hpp"

Algorithm::Algorithm(std::string name):
    Job(name)
{
}

Algorithm::~Algorithm()
{
}

void Algorithm::setInput(std::string name, Node* node)
{
}

void Algorithm::execute(std::unordered_map<std::string,Node*> input)
{
    //convenience - adds all inputs and then executes
}

