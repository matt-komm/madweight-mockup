#include "Variable.hpp"

Variable::Variable(std::string name, Node* owner):
    _name(name),
    _owner(owner),
    _parent(0)
{
}

Variable::~Variable()
{
}

const Variable* Variable::getParent() const
{
    return _parent;
}

bool Variable::hasParent() const
{
    return _parent != 0;
}

void Variable::addChild(Variable* variable)
{
    variable->_parent=this;
    //std::cout<<"variable: "<<_name<<" -> addChild:"<<variable->getName()<<std::endl;
    _children.push_back(variable);
}

void Variable::updateChildren()
{
    for (unsigned int ichild = 0; ichild < _children.size(); ++ichild)
    {
        //std::cout<<"variable: "<<_name<<" -> update:"<<_children[ichild]->getName()<<std::endl;
        for (unsigned int index = 0; index<this->size(); ++index)
        {
            _children[ichild]->value(index)=this->value(index);
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Variable* variable)
{
    os<<"class = Variable: { name="<<variable->getName()<<"}";
    return os;
}
/*
bool operator==(const Variable* var1, const Variable* var2)
{
    return (var1->getName()==var2->getName()) && (var1->getOwner()==var2->getOwner());
}
*/
