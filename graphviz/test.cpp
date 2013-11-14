#include "GraphViz.hpp"
#include "Node.hpp"
#include "Scalar.hpp"

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
            output->value()=2.0;
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
            output->value()=6.0;
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

int main()
{
    TestInputNode1 input1 = TestInputNode1();
    TestInputNode2 input2 = TestInputNode2();
    TestComputingNode computing = TestComputingNode();
    computing.connectInput(computing.getInput<Scalar>("input"),input1.getOutput<Scalar>("const"));
    computing.connectInputAll(&input2);


    input1.execute();
    input1.updateOutput();
    input2.execute();
    input2.updateOutput();
    computing.execute();
    computing.updateOutput();

    GraphViz* g = GraphViz::createFromNode(&computing);
    g->render("graph");
    return 0;
}


