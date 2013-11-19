#ifndef __CONFIGURATION_H__
#define __CONFIGURATION_H__

#include <unordered_map>
#include <vector>
#include <string>


class Configuration
{
    public:
        class GenericType
        {
            protected:
                union Data
                {
                    const bool* boolean;
                    const int* integer;
                    const unsigned int* uinteger;
                    const double* floatingpoint;
                    const std::string* string;
                    const std::vector<GenericType*>* list;
                    const std::unordered_map<std::string, GenericType*>* map;
                };
                enum TYPE
                {
                    BOOLEAN, INTEGER, UINTEGER, FLOATINGPOINT, STRING, LIST, MAP
                };

                Data _data;
                TYPE _type;
                GenericType(GenericType::TYPE type):
                    _type(type)
                {
                }
            public:
                static GenericType* create(const bool boolean)
                {
                    GenericType* g = new GenericType(BOOLEAN);
                    g->_data.boolean=new bool(boolean);
                    return g;
                }
                static GenericType* create(const int integer)
                {
                    GenericType* g = new GenericType(INTEGER);
                    g->_data.integer=new int(integer);
                    return g;
                }
                static GenericType* create(const unsigned int uinteger)
                {
                    GenericType* g = new GenericType(UINTEGER);
                    g->_data.uinteger=new unsigned int(uinteger);
                    return g;
                }
                static GenericType* create(const double floatingpoint)
                {
                    GenericType* g = new GenericType(FLOATINGPOINT);
                    g->_data.floatingpoint=new double(floatingpoint);
                    return g;
                }
                static GenericType* create(const std::string string)
                {
                    GenericType* g = new GenericType(STRING);
                    g->_data.string=new std::string(string);
                    return g;
                }
                static GenericType* create(const std::vector<GenericType*>* list)
                {
                    GenericType* g = new GenericType(LIST);
                    g->_data.list=list;
                    return g;
                }
                static GenericType* create(const std::unordered_map<std::string,GenericType*>* map)
                {
                    GenericType* g = new GenericType(MAP);
                    g->_data.map=map;
                    return g;
                }

        };
    protected:
        std::unordered_map<std::string,GenericType*> _map;
    public:
        Configuration();
        ~Configuration();

};

#endif

