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
                    bool* boolean;
                    int* integer;
                    int* uinteger;
                    double* floatingpoint;
                    std::string* string;
                    std::vector<GenericType*>* list;
                    std::unordered_map<std::string, GenericType*>* map;
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
                static GenericType* create(bool boolean)
                {
                    GenericType* g = new GenericType(BOOLEAN);
                    *g->_data.boolean=boolean;
                    return g;
                }
                static GenericType* create(int integer)
                {
                    GenericType* g = new GenericType(INTEGER);
                    *g->_data.integer=integer;
                    return g;
                }
                static GenericType* create(double floatingpoint)
                {
                    GenericType* g = new GenericType(FLOATINGPOINT);
                    *g->_data.floatingpoint=floatingpoint;
                    return g;
                }
                static GenericType* create(std::string string)
                {
                    GenericType* g = new GenericType(STRING);
                    *g->_data.string=string;
                    return g;
                }
                static GenericType* create(std::vector<GenericType*>* list)
                {
                    GenericType* g = new GenericType(LIST);
                    g->_data.list=list;
                    return g;
                }
                static GenericType* create(std::unordered_map<std::string,GenericType*>* map)
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

