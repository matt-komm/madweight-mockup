#include "Algorithm.hpp"

Algorithm::Algorithm()
{
}

Algorithm::~Algorithm()
{
}

void Algorithm::setInput(std::string name, Node* node)
{
    _input[name]=node;
}

void Algorithm::run(std::unordered_map<std::string,Node*> input)
{
    _input=input;
}

