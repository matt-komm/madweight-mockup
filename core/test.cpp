#include "Scalar.hpp"
#include "NVector.hpp"
#include "Node.hpp"
#include <stdlib.h>

class TestInputNode1:
    public Node
{
    protected:
        Scalar* output;
        NVector* vectorOutput;
    public:
        TestInputNode1():
            Node()
        {
            output = createVariable<Scalar>("const");
            vectorOutput = createVariable<NVector>("vector");
            vectorOutput->setSize(3);

        }
        virtual void execute()
        {
            output->value()=(rand()%10000)*0.01;
            for (unsigned int i = 0; i<vectorOutput->size();++i)
            {
                vectorOutput->value(i)=(rand()%10000)*0.01;
            }
        }
};

class TestInputNode2:
    public Node
{
    protected:
        Scalar* output;
        NVector* vectorOutput;
    public:
        TestInputNode2():
            Node()
        {
            output = createVariable<Scalar>("auto");
            vectorOutput = createVariable<NVector>("vector");
            vectorOutput->setSize(3);
        }
        virtual void execute()
        {
            output->value()=(rand()%10000)*0.01;
            for (unsigned int i = 0; i<vectorOutput->size();++i)
            {
                vectorOutput->value(i)=(rand()%10000)*0.01;
            }
        }
};

class TestComputingNode:
    public Node
{
    protected:
        const Scalar* input1;
        const Scalar* input2;
        const NVector* input3;
        Scalar* output;
    public:
        TestComputingNode():
            Node()
        {
            output = createVariable<Scalar>("computingresult");
            input1 = getVariable<Scalar>("input");
            input2 = getVariable<Scalar>("auto");
            input3 = getVariable<NVector>("vector");
        }

        virtual void execute()
        {
            output->value()=input1->value()*2+input2->value()+input3->value(2);
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
    MultiplyNode* m1 = MultiplyNode::multiply(input1.getOutput<Scalar>("const"),input2.getOutput<Scalar>("auto"));
    MultiplyNode* m2 = MultiplyNode::multiply(input1.getOutput<NVector>("vector"),input2.getOutput<NVector>("vector"));

    //AddNode a(input1.getOutput<Scalar>("const"),input2.getOutput<Scalar>("auto"));

    input1.execute();
    input1.updateOutput();
    input2.execute();
    input2.updateOutput();
    computing.execute();
    computing.updateOutput();
    m1->execute();
    m1->updateOutput();
    m2->execute();
    m2->updateOutput();
    //a.execute();
    //a.updateOutput();

    std::cout<<"input1:"<<input1.getOutput<Scalar>("const")->value()<<std::endl;
    std::cout<<"input2:"<<input2.getOutput<Scalar>("auto")->value()<<std::endl;
    std::cout<<"computing:"<<computing.getOutput<Scalar>("computingresult")->value()<<std::endl;

    std::cout<<"multiply scalar:"<<m1->getOutput<Scalar>("product")->value()<<std::endl;
    std::cout<<"multiply nvector:"<<m2->getOutput<Scalar>("product")->value()<<std::endl;
    //std::cout<<"add:"<<a.getOutput<Scalar>("result")<<std::endl;
    return 0;
}

