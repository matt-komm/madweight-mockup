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
        MultiplyNode()
        {

        }

        void _addMultiplicationPair(Variable* var1, Variable* var2)
        {
            Variable* _var1 = var1->clone(this);
            var1->addChild(_var1);
            Variable* _var2 = var2->clone(this);
            var2->addChild(_var2);
            OpVariableInterface* opVariable = var1->createMultiplication("product", this, var2);
            _opVariables.push_back(opVariable);
            _input.push_back(var1);
            _input.push_back(var2);
            _output.push_back(opVariable->getTarget());
        }

        std::vector<OpVariableInterface* > _opVariables;
    public:
        static MultiplyNode* multiply(Variable* var1, Variable* var2)
        {
            MultiplyNode* node = new MultiplyNode();
            node->_addMultiplicationPair(var1,var2);
            return node;

        }
        static MultiplyNode* multiply(Node* node1, Node* node2)
        {

        }
        virtual ~MultiplyNode()
        {
            for (unsigned int i = 0; i < _opVariables.size(); ++i)
            {
                delete _opVariables[i];
            }
        }

        virtual void execute()
        {
            for (unsigned int i = 0; i < _opVariables.size(); ++i)
            {
                _opVariables[i]->execute();
            }
        }
};

/*
class AddNode:
    public Node
{
    protected:
        Addable* _addable;
        Variable* _variable;
        Variable* _result;
    public:
        AddNode(Variable* var1, Variable* var2);
        virtual ~AddNode();
        virtual void execute();

};
*/
#endif

