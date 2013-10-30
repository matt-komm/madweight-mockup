#ifndef __Variable_H__
#define __Variable_H__

#include <string>
#include <vector>
#include <iostream>
class Node;



class Variable
{
    protected:
        const std::string _name;
        Node* _owner;
        std::vector<Variable*> _children;
        Variable* _parent;

    public:
        enum TYPE {SCALAR};

        Variable(std::string name, Node* owner);
        virtual ~Variable();

        virtual Variable* clone(Node* owner) = 0;

        virtual unsigned int size() = 0;

        virtual const double& value(const unsigned int index=0) const = 0;
        virtual double& value(const unsigned int index=0) = 0;

        virtual void addChild(Variable* variable);

        virtual void updateChildren();
        virtual const Variable* getParent() const;
        virtual bool hasParent() const;
        virtual TYPE getType()=0;

        virtual Variable* multiply(std::string name, Node* owner, Variable* var) = 0;
        virtual void multiply(Variable* target, Variable* input) = 0;

        virtual Variable* add(std::string name, Node* owner, Variable* var) = 0;
        virtual void add(Variable* target, Variable* input) = 0;

        const std::string getName() const
        {
            return _name;
        }


        Node* getOwner() const
        {
            return _owner;
        }

};

std::ostream& operator<<(std::ostream& os, const Variable* variable);
//bool operator==(const Variable* var1, const Variable* var2);
#endif

