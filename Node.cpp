#include "Node.hpp"
#include "Scalar.hpp"

Node::Node()
{
}

Node::~Node()
{

    for (unsigned int i=0; i<_input.size(); ++i)
    {
        delete _input[i];
    }
    for (unsigned int i=0; i<_output.size(); ++i)
    {
        delete _output[i];
    }

}

template<class VARIABLE> VARIABLE* Node::getOutput(std::string name)
{
    int index = findOutputVariable(name);
    if (index<0)
    {
        return 0;
    }
    else
    {
        return dynamic_cast<VARIABLE*>(_output[index]);
    }
}
template Scalar* Node::getOutput<Scalar>(std::string name);

template<class VARIABLE> const VARIABLE* Node::getInput(std::string name) const
{
    int index = findInputVariable(name);
    if (index<0)
    {
        return 0;
    }
    else
    {
        return dynamic_cast<VARIABLE*>(_input[index]);
    }
}
template const Scalar* Node::getInput<Scalar>(std::string name) const;

void Node::updateOutput()
{
    for (unsigned int i = 0; i<_output.size(); ++i)
    {
        _output[i]->updateChildren();
    }
}

void Node::connectInputAll(Node* node)
{
    for (unsigned int i = 0; i<_input.size(); ++i)
    {
        Variable* var = node->getOutput<Variable>(_input[i]->getName());
        if (var!=0)
        {
            connectInput(_input[i],var);
        }
    }
}

void Node::connectInput(const Variable* input, Variable* output)
{
    int index = findInputVariable(input->getName());
    if (index>=0)
    {
        output->addChild(_input[index]);
    }
}

template<class VARIABLE> VARIABLE* Node::createVariable(std::string name)
{
    if (findOutputVariable(name)<0)
    {
        VARIABLE* var = (new VARIABLE(name,this));
        _output.push_back(var);
        return var;
    }
    return 0;
}
template Scalar* Node::createVariable<Scalar>(std::string name);

template<class VARIABLE> const VARIABLE* Node::getVariable(std::string name)
{
    int index = findInputVariable(name);
    if (index<0)
    {
        VARIABLE* var = (new VARIABLE(name,0));
        _input.push_back(var);
        return var;
    }
    else
    {
        return dynamic_cast<VARIABLE*>(_input[index]);
    }
}
template const Scalar* Node::getVariable<Scalar>(std::string name);

int Node::findInputVariable(std::string name) const
{
    int index=-1;
    for (unsigned int i = 0; i<_input.size();++i)
    {
        if (_input[i]->getName()==name)
        {
            index=i;
            break;
        }
    }
    return index;
}

int Node::findOutputVariable(std::string name) const
{
    int index=-1;
    for (unsigned int i = 0; i<_output.size();++i)
    {
        if (_output[i]->getName()==name)
        {
            index=i;
            break;
        }
    }
    return index;
}

MultiplyNode::MultiplyNode(Variable* var1, Variable* var2):
    Node()
{
    _var1=var1->clone(this);
    _input.push_back(_var1);
    connectInput(_var1,var1);

    _var2=var2->clone(this);
    _input.push_back(_var2);
    connectInput(_var2,var2);

    _result = var1->multiply("result",this,_var2);
    _output.push_back(_result);
}

MultiplyNode::~MultiplyNode()
{
}

void MultiplyNode::execute()
{
    _var1->multiply(_result,_var2);
}


AddNode::AddNode(Variable* var1, Variable* var2):
    Node()
{
    _var1=var1->clone(this);
    _input.push_back(_var1);
    connectInput(_var1,var1);

    _var2=var2->clone(this);
    _input.push_back(_var2);
    connectInput(_var2,var2);

    _result = var1->add("result",this,_var2);
    _output.push_back(_result);
}

AddNode::~AddNode()
{
}

void AddNode::execute()
{
    _var1->add(_result,_var2);
}
