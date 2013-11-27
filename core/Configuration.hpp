#ifndef __CONFIGURATION_H__
#define __CONFIGURATION_H__

#include <unordered_map>
#include <vector>
#include <string>

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
            std::vector<GenericType*>* list;
            std::unordered_map<std::string, GenericType*>* map;
        };
        enum TYPE
        {
            BOOLEAN, INTEGER, UINTEGER, FLOATINGPOINT, STRING, LIST, MAP
        };


        TYPE _type;
        Data _data;
    public:
        static GenericType& createEmpty()
    	{
        	GenericType* gt = new GenericType(std::unordered_map<std::string,GenericType*>());
        	return *gt;
    	}

        GenericType(const GenericType& type):
            _type(type._type),
            _data(type._data)
        {
        }
        GenericType(bool boolean):
            _type(BOOLEAN)
        {
            _data.boolean=new bool(boolean);
        }
        GenericType(int integer):
            _type(INTEGER)
        {
            _data.integer=new int(integer);
        }
        GenericType(unsigned int uinteger):
            _type(UINTEGER)
        {
            _data.uinteger=new unsigned int(uinteger);
        }
        GenericType(double floatingpoint):
            _type(FLOATINGPOINT)
        {
            _data.floatingpoint=new double(floatingpoint);
        }
        GenericType(std::string string):
            _type(STRING)
        {
            _data.string=new std::string(string);
        }
        GenericType(std::vector<GenericType*> list):
            _type(LIST)
        {
            _data.list=new std::vector<GenericType*>(list);
        }
        GenericType(std::unordered_map<std::string,GenericType*> map):
            _type(MAP)
        {
            _data.map=new std::unordered_map<std::string,GenericType*>(map);
        }

        GenericType get(std::string name)
        {
            if (_type==MAP)
            {
                if (_data.map->find(name)!=_data.map->end())
                {
                    return (*_data.map)[name];
                }
                else
                {
                    throw std::string("config name '"+name+"' does not exists!");
                    return 0;
                }
            }
            else
            {
                throw std::string("config type is not a map! Cannot use 'get' method.");
                return 0;
            }
        }

        void insert(GenericType type)
        {
            if (_type==LIST)
            {
                _data.list->push_back(new GenericType(type));
            }
            else
            {
                throw std::string("config type is not a list! Cannot use 'insert(GenericType*)' method.");
            }
        }

        void insert(std::string name, GenericType type)
        {
            if (_type==MAP)
            {
                if (_data.map->find(name)!=_data.map->end())
                {
                    delete (*_data.map)[name];
                }
                (*_data.map)[name]=new GenericType(type);
            }
            else
            {
                throw std::string("config type is not a map! Cannot use 'insert(std::string, GenericType*)' method.");
            }
        }

        bool exists(std::string name)
        {
        	if (_type==MAP)
			{
				return _data.map->find(name)!=_data.map->end();
			}
        	else
        	{
                throw std::string("config type is not a map! Cannot use 'exists(std::string)' method.");
                return false;
        	}

        }

        unsigned int size()
        {
        	if (_type==LIST)
			{
				return _data.list->size();
			}
			else
			{
				throw std::string("config type is not a list! Cannot use 'size()' method.");
				return 0;
			}
        }
};

typedef GenericType Configuration;

#endif

