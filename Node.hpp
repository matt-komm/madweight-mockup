#ifndef __NODE_H__
#define __NODE_H__

#include <vector>
#include "Variable.hpp"

class Node
{
    protected:
        std::vector<Variable*> _input;
        std::vector<Variable*> _output;

    public:
        Node();
        virtual ~Node();

        void connectInputAll(Node* output);
        void connectInput(const Variable* input, Variable* output);

        template<class VARIABLE> VARIABLE* createVariable(std::string name);
        template<class VARIABLE> const VARIABLE* getVariable(std::string name);

        int findInputVariable(std::string name) const;
        int findOutputVariable(std::string name) const;

        template<class VARIABLE> VARIABLE* getOutput(std::string name);
        template<class VARIABLE> const VARIABLE* getInput(std::string name) const;

        void updateOutput();

        unsigned int getOutputSize() const
        {
            return _output.size();
        }

        unsigned int getInputSize() const
        {
            return _input.size();
        }

        Variable* getOutput(unsigned int index)
        {
            return _output[index];
        }

        const Variable* getInput(unsigned int index) const
        {
            return _input[index];
        }

};

class MultiplyNode:
    public Node
{
    protected:
        Variable* _var1;
        Variable* _var2;
        Variable* _result;
    public:
        MultiplyNode(Variable* _var1, Variable* _var2);
        virtual ~MultiplyNode();

        virtual void execute();
};

class AddNode:
    public Node
{
    protected:
        Variable* _var1;
        Variable* _var2;
        Variable* _result;
    public:
        AddNode(Variable* _var1, Variable* _var2);
        virtual ~AddNode();
        virtual void execute();

};

#endif

