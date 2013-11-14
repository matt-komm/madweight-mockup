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

MultiplyNode::MultiplyNode():
    Node()
{
    /*
    Variable* var1clone = var1->clone(this);
    _input.push_back(var1clone);
    connectInput(var1clone,var1);

    _variable = var2->clone(this);
    _input.push_back(_variable);
    connectInput(_variable,var2);

    _multipliable = dynamic_cast<Multipliable*>(var1clone);
    if (_multipliable)
    {
        _result = _multipliable->multiply("result",this,_variable);
        _output.push_back(_result);
    }
    else
    {
        throw std::string("variables cannot be multiplied: "+var1->getName()+"; "+var2->getName());
    }
    */
}

MultiplyNode* MultiplyNode::multiply(Variable* var1, Variable* var2)
{

}

MultiplyNode* MultiplyNode::multiply(Node* node1, Node* node2)
{

}

MultiplyNode::~MultiplyNode()
{
}

void MultiplyNode::execute()
{
    //_multipliable->multiply(_result,_variable);
}

/*
AddNode::AddNode(Variable* var1, Variable* var2):
    Node()
{
    Variable* var1clone = var1->clone(this);
    _input.push_back(var1clone);
    connectInput(var1clone,var1);

    _variable = var2->clone(this);
    _input.push_back(_variable);
    connectInput(_variable,var2);

    _addable = dynamic_cast<Addable*>(var1clone);
    if (_addable)
    {
        _result = _addable->add("result",this,_variable);
        _output.push_back(_result);
    }
    else
    {
        throw std::string("variables cannot be summed: "+var1->getName()+"; "+var2->getName());
    }
}

AddNode::~AddNode()
{
}

void AddNode::execute()
{
    _addable->add(_result,_variable);
}

*/
