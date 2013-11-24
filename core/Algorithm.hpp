#ifndef __ALGORITHM_H__
#define __ALGORITHM_H__

#include "Node.hpp"
#include "Job.hpp"

#include <string>
#include <unordered_map>

class Algorithm:
    public Job
{
    protected:
        std::unordered_map<std::string,Node*> _input;
    public:
        Algorithm(std::string name);
        virtual ~Algorithm();
        void setInput(std::string name, Node* node);
        void execute(std::unordered_map<std::string,Node*> input);
};

#endif

