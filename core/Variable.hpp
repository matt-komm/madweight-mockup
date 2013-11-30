#ifndef __Variable_H__
#define __Variable_H__


#include <string>
#include <vector>
#include <iostream>

#include "defs.hpp"

//#include "Node.hpp"
class Node;

class OpVariableInterface;


class Variable
{
    protected:
        const std::string _name;
        Node* _owner;
        std::vector<Variable*> _children;
        Variable* _parent;

    public:
        enum TYPE {SCALAR,NVECTOR,LORENTZVECTOR};

        Variable(std::string name, Node* owner);
        virtual ~Variable();

        virtual Variable* clone(Node* owner) = 0;

        virtual void setSize(unsigned int size) = 0;
        virtual unsigned int size() const = 0;

        virtual const double& value(const unsigned int index=0) const = 0;
        virtual double& value(const unsigned int index=0) = 0;

        virtual void addChild(Variable* variable);
        virtual const std::vector<Variable*> getChildren() const
        {
            return _children;
        }

        virtual void updateChildren();
        virtual const Variable* getParent() const;
        virtual bool hasParent() const;
        virtual TYPE getType() const =0;

        virtual OpVariableInterface* createMultiplication(std::string name, Node* owner, const Variable* variable) const = 0;
        //virtual void multiply(Variable* target, const Variable* variable) const = 0;

        const std::string getName() const
        {
            return _name;
        }

        Node* getOwner() const
        {
            return _owner;
        }

};

class OpVariableInterface
{
    public:
        virtual void execute() = 0;
        virtual Variable* getTarget() = 0;

};

template<class TARGET, class VAR1, class VAR2>
class OpVariable:
    public OpVariableInterface
{
    protected:
        void (*_opFunction)(TARGET* target, const VAR1* var1, const VAR2* var2);
        TARGET* _target;
        const VAR1* _var1;
        const VAR2* _var2;

    public:
        OpVariable(	void (*opFunction)(TARGET* target, const VAR1* var1, const VAR2* var2),
                    TARGET* target, const VAR1* var1, const VAR2* var2):
                        _opFunction(opFunction),
                        _target(target),
                        _var1(var1),
                        _var2(var2)
        {
        }
        virtual void execute()
        {
            _opFunction(_target,_var1,_var2);
        }
        virtual Variable* getTarget()
        {
            return _target;
        }

};

#endif

