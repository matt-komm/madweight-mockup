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
            public:
                GenericType(const bool boolean):
                    _type(BOOLEAN)
                {
                    _data.boolean=new bool(boolean);
                }
                GenericType(const int integer):
                    _type(INTEGER)
                {
                    _data.integer=new int(integer);
                }
                GenericType(const unsigned int uinteger):
                    _type(UINTEGER)
                {
                    _data.uinteger=new unsigned int(uinteger);
                }
                GenericType(const double floatingpoint):
                    _type(FLOATINGPOINT)
                {
                    _data.floatingpoint=new double(floatingpoint);
                }
                GenericType(const std::string string):
                    _type(STRING)
                {
                    _data.string=new std::string(string);
                }
                GenericType(const std::vector<GenericType*>* list):
                    _type(LIST)
                {
                    _data.list=list;
                }
                GenericType(const std::unordered_map<std::string,GenericType*>* map):
                    _type(MAP)
                {
                    _data.map=map;
                }
        };
    protected:
        std::unordered_map<std::string,GenericType*> _map;
    public:
        Configuration();
        void insert(std::string name, GenericType type)
        {
            _map[name]=new GenericType(type);
        }
        ~Configuration();

};

#endif

