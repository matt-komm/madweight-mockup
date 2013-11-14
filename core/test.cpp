#include "Scalar.hpp"
#include "Node.hpp"
#include <stdlib.h>

class TestInputNode1:
    public Node
{
    protected:
        Scalar* output;
    public:
        TestInputNode1():
            Node()
        {
            output = createVariable<Scalar>("const");
        }
        virtual void execute()
        {
            output->value()=(rand()%10000)*0.0001;
        }
};

class TestInputNode2:
    public Node
{
    protected:
        Scalar* output;
    public:
        TestInputNode2():
            Node()
        {
            output = createVariable<Scalar>("auto");
        }
        virtual void execute()
        {
            output->value()=(rand()%10000)*0.0001;
        }
};

class TestComputingNode:
    public Node
{
    protected:
        const Scalar* input1;
        const Scalar* input2;
        Scalar* output;
    public:
        TestComputingNode():
            Node()
        {
            output = createVariable<Scalar>("computingresult");
            input1 = getVariable<Scalar>("input");
            input2 = getVariable<Scalar>("auto");
        }

        virtual void execute()
        {
            output->value()=input1->value()*2+input2->value();
        }
};

#include <iostream>

int main()
{
    TestInputNode1 input1 = TestInputNode1();
    TestInputNode2 input2 = TestInputNode2();
    TestComputingNode computing = TestComputingNode();
    computing.connectInput(computing.getInput<Scalar>("input"),input1.getOutput<Scalar>("const"));
    computing.connectInputAll(&input2);
    MultiplyNode m(input1.getOutput<Scalar>("const"),input2.getOutput<Scalar>("auto"));
    AddNode a(input1.getOutput<Scalar>("const"),input2.getOutput<Scalar>("auto"));

    input1.execute();
    input1.updateOutput();
    input2.execute();
    input2.updateOutput();
    computing.execute();
    computing.updateOutput();
    m.execute();
    m.updateOutput();
    a.execute();
    a.updateOutput();

    std::cout<<"input1:"<<input1.getOutput<Scalar>("const")<<std::endl;
    std::cout<<"input2:"<<input2.getOutput<Scalar>("auto")<<std::endl;
    std::cout<<"computing:"<<computing.getOutput<Scalar>("computingresult")<<std::endl;

    std::cout<<"multiply:"<<m.getOutput<Scalar>("result")<<std::endl;
    std::cout<<"add:"<<a.getOutput<Scalar>("result")<<std::endl;
    return 0;
}

