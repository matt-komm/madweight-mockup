#include "gtest/gtest.h"

#include "Configuration.hpp"
#include "Scalar.hpp"
#include "NVector.hpp"
#include "LorentzVector.hpp"
#include "Node.hpp"
#include "Graph.hpp"

TEST(Configuration, list)
{
    Configuration& conf = Configuration::createEmptyList();
    //empty list has size 0
    EXPECT_EQ(conf.size(),(unsigned int)0);
    //cannot insert keys into list
    EXPECT_THROW(conf.insertDictEntry("test","test"),std::string);
    //cannot test if keys exist
    EXPECT_THROW(conf.exists("test"),std::string);
    //cannot get an element by its name
    EXPECT_THROW(conf.get("test").value<Configuration>(),std::string);
    
    //can insert string
    EXPECT_NO_THROW(conf.insertListEntry("test"));
    //can insert int
    EXPECT_NO_THROW(conf.insertListEntry(1));
    //can insert uint
    EXPECT_NO_THROW(conf.insertListEntry((unsigned int)10));
    //can insert double
    EXPECT_NO_THROW(conf.insertListEntry(100.5));
    //can insert bool
    EXPECT_NO_THROW(conf.insertListEntry(true));
    //can insert empty configuration (type == NONE)
    EXPECT_NO_THROW(conf.insertListEntry(Configuration()));
    //size needs to be 6
    EXPECT_EQ(conf.size(),(unsigned int)6);
    
    EXPECT_EQ(conf.get(0).value<std::string>(),"test");
    EXPECT_EQ(conf.get(1).value<int>(),1);
    EXPECT_EQ(conf.get(2).value<unsigned int>(),(unsigned int)10);
    EXPECT_EQ(conf.get(3).value<double>(),100.5);
    EXPECT_EQ(conf.get(4).value<bool>(),true);
    //EXPECT_EQ(conf.get<Configuration>(5),0);
    
    EXPECT_THROW(conf.get(6).value<Configuration>(),std::string);
}

TEST(Variable, NVector)
{
	NVector v("test",0,3);
	v.value(0)=1;
	v.value(1)=2;
	v.value(2)=3;
	EXPECT_EQ(v.size(),(unsigned int)3);
	EXPECT_EQ(v.value(),(unsigned int)1);
	EXPECT_EQ(v.value(0),(unsigned int)1);
	EXPECT_EQ(v.value(1),(unsigned int)2);
	EXPECT_EQ(v.value(2),(unsigned int)3);
}

TEST(Node, creating)
{
	class TestInputNode:
	    public Node
	{
	    protected:
	        Scalar* output;
	        NVector* vectorOutput;
	        LorentzVector* lvec;
	    public:
	        TestInputNode():
	            Node()
	        {
	            output = createVariable<Scalar>("const");
	            vectorOutput = createVariable<NVector>("vector");
	            vectorOutput->setSize(3);
	            lvec= createVariable<LorentzVector>("momenta");

	        }
	        virtual void execute()
	        {
	            output->value()=12345.0;
	            for (unsigned int i = 0; i<vectorOutput->size();++i)
	            {
	                vectorOutput->value(i)=1;
	            }
	            lvec->value(0)=100;
	            lvec->value(1)=-10;
	            lvec->value(2)=-10;
	            lvec->value(3)=-10;
	        }
	};
	TestInputNode node;
	EXPECT_EQ(node.getOutputSize(),(unsigned int)3);
	node.execute();
	EXPECT_EQ(node.getOutput(0)->value(),12345.0);
	EXPECT_EQ(node.getOutput(1)->value(),1.0);
	EXPECT_EQ(node.getOutput(2)->value(),100.0);

}
