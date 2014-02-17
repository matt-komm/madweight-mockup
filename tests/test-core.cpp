#include "gtest/gtest.h"

#include "Configuration.hpp"

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
    EXPECT_THROW(conf.get<Configuration>("test"),std::string);
    
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
    
    EXPECT_EQ(conf.get<std::string>(0),"test");
    EXPECT_EQ(conf.get<int>(1),1);
    EXPECT_EQ(conf.get<unsigned int>(2),(unsigned int)10);
    EXPECT_EQ(conf.get<double>(3),100.5);
    EXPECT_EQ(conf.get<bool>(4),true);
    //EXPECT_EQ(conf.get<Configuration>(5),0);
    
    EXPECT_THROW(conf.get<Configuration>(6),std::string);
}
