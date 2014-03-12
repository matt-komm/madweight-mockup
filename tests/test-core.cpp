#include "gtest/gtest.h"

#include "Configuration.hpp"
#include "simple_graph.hpp"

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

TEST(Graph, simple)
{
    
}
