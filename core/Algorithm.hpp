#ifndef __ALGORITHM_H__
#define __ALGORITHM_H__

#include "Node.hpp"

#include <unordered_map>

class Algorithm
{
    protected:
        std::unordered_map<std::string,Node*> _input;
    public:
        Algorithm();
        virtual ~Algorithm();
        void setInput(std::string name, Node* node);
        void run(std::unordered_map<std::string,Node*> input);
        virtual void run() = 0;
};

#endif

