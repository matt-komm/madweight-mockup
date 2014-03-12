#ifndef __CONFIGURATION_H__
#define __CONFIGURATION_H__

#include <unordered_map>
#include <vector>
#include <string>
#include <typeinfo>

struct ConfigurationType
{
	enum TYPE
	{
		NONE, BOOLEAN, INTEGER, UINTEGER, FLOATINGPOINT, STRING, LIST, MAP
	};
};

class Configuration
{
    protected:
        union Data
        {
            bool* boolean;
            int* integer;
            unsigned int* uinteger;
            double* floatingpoint;
            std::string* string;
            std::vector<Configuration*>* list;
            std::unordered_map<std::string, Configuration*>* map;
        };

        ConfigurationType::TYPE _type;
        Data _data;
    public:
        static Configuration& createEmptyDict()
    	{
        	Configuration* gt = new Configuration(std::unordered_map<std::string,Configuration*>());
        	return *gt;
    	}
        static Configuration& createEmptyList()
		{
			Configuration* gt = new Configuration(std::vector<Configuration*>());
			return *gt;
		}

        Configuration(const Configuration& type):
            _type(type._type),
            _data(type._data)
        {
        }


        Configuration():
			_type(ConfigurationType::NONE)
		{
		}
        Configuration(int integer):
            _type(ConfigurationType::INTEGER)
        {
            _data.integer=new int(0);
            *_data.integer=integer;
        }
        Configuration(unsigned int uinteger):
            _type(ConfigurationType::UINTEGER)
        {
            _data.uinteger=new unsigned int(0);
            *_data.uinteger=uinteger;
        }
        Configuration(double floatingpoint):
            _type(ConfigurationType::FLOATINGPOINT)
        {
            _data.floatingpoint=new double(0.0);
            *_data.floatingpoint=floatingpoint;
        }
        Configuration(const char* string):
			_type(ConfigurationType::STRING)
		{
			_data.string=new std::string("");
			*_data.string=string;
		}

        Configuration(std::vector<Configuration*> list):
            _type(ConfigurationType::LIST)
        {
            _data.list=new std::vector<Configuration*>();
            *_data.list=list;
        }
        Configuration(std::unordered_map<std::string,Configuration*> map):
            _type(ConfigurationType::MAP)
        {
            _data.map=new std::unordered_map<std::string,Configuration*>();
            *_data.map=map;
        }

        //this method screws things up:
        //http://stackoverflow.com/questions/1636181/function-method-overloading-c-data-type-confusion
        //std::string can be casted to char* and then to bool when used as method argument for an overloaded function -> use const char* & bool as arguments instead


        Configuration(bool boolean):
            _type(ConfigurationType::BOOLEAN)
        {
            _data.boolean=new bool(false);
            *_data.boolean=boolean;
        }

        template<class TYPE> TYPE value()
        {
        	if (_type==ConfigurationType::BOOLEAN && typeid(TYPE)==typeid(bool))
        	{
        		return *(TYPE*)(_data.boolean);
        	}
        	else if (_type==ConfigurationType::INTEGER && typeid(TYPE)==typeid(int))
			{
				return *(TYPE*)(_data.integer);
			}
        	else if (_type==ConfigurationType::UINTEGER && typeid(TYPE)==typeid(unsigned int))
			{
				return *(TYPE*)(_data.uinteger);
			}
        	else if (_type==ConfigurationType::FLOATINGPOINT && typeid(TYPE)==typeid(double))
			{
				return *(TYPE*)(_data.floatingpoint);
			}
        	else if (_type==ConfigurationType::STRING && typeid(TYPE)==typeid(std::string))
			{
				return *(TYPE*)(_data.string);
			}
        	else if (_type==ConfigurationType::NONE)
        	{
        		return (TYPE)0;
        	}
        	throw std::string("casting not possible or allowed");
        	return (TYPE)0;
        }

        inline ConfigurationType::TYPE getType()
        {
        	return _type;
        }

        Configuration get(std::string name)
        {
            if (_type==ConfigurationType::MAP)
            {
                if (_data.map->find(name)!=_data.map->end())
                {
                	return *(*_data.map)[name];
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

        Configuration get(unsigned int index)
        {
            if (_type==ConfigurationType::LIST)
            {
                if (index<this->size())
                {
				    return *(*_data.list)[index];
			    }
			    else
			    {
			        throw std::string("index for config of type list is out of range");
                    return 0;
			    }
            }
            else
            {
                throw std::string("config type is not a map! Cannot use 'get' method.");
                return 0;
            }
        }

        void insertListEntry(Configuration type)
        {
            if (_type==ConfigurationType::LIST)
            {
                _data.list->push_back(new Configuration(type));
            }
            else
            {
                throw std::string("config type is not a list! Cannot use 'insert(GenericType*)' method.");
            }
        }

        void insertDictEntry(std::string name, Configuration type)
        {
            if (_type==ConfigurationType::MAP)
            {
                if (_data.map->find(name)!=_data.map->end())
                {
                    delete (*_data.map)[name];
                }
                (*_data.map)[name]=new Configuration(type);
            }
            else
            {
                throw std::string("config type is not a map! Cannot use 'insert(std::string, GenericType*)' method.");
            }
        }

        bool exists(std::string name)
        {
        	if (_type==ConfigurationType::MAP)
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
        	if (_type==ConfigurationType::LIST)
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

//typedef GenericType Configuration;

#endif

