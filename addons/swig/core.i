%include stl.i
%include std_set.i
%include std_multiset.i
%include std_map.i
%include std_pair.i
%include std_multimap.i
%include std_vector.i
%include std_string.i
%include stdint.i
%include std_container.i

/* generic exception handler for C++ exception */
%exception {
   try {
      $action
   } catch (std::string &e) {
      PyErr_SetString(PyExc_RuntimeError, e.c_str());
      return NULL;
   } catch (std::exception &e) {
      PyErr_SetString(PyExc_RuntimeError, const_cast<char*>(e.what()));
      return NULL;
   }
}

%module(directors="1") mwcore
%{
    #include "Configuration.hpp"
    
    #include "Graph.hpp"

    #include "Job.hpp"
    #include "JobFactory.hpp"
    #include "Algorithm.hpp"
    
    #include "Node.hpp"
    #include "Module.hpp"
    
    #include "Variable.hpp"
    #include "Scalar.hpp"
    #include "NVector.hpp"
    #include "LorentzVector.hpp"
    
%}


%rename(insertDictEntryConfiguration) Configuration::insertDictEntry(std::string,Configuration);
%rename(insertListEntryConfiguration) Configuration::insertListEntry(Configuration);

%include "Configuration.hpp"


%template(valueString) Configuration::value<std::string>;
%template(valueInteger) Configuration::value<int>;
%template(valueUnsignedInteger) Configuration::value<unsigned int>;
%template(valueBoolean) Configuration::value<bool>;
%template(valueDouble) Configuration::value<double>;

%template(ConfigurationList) std::vector<Configuration*>;
%template(valueList) Configuration::value<ConfigurationList>;
%template(ConfigurationDict) std::map<std::string, Configuration*>;
%template(valueDict) Configuration::value<ConfigurationDict>;

%inline
%{
    typedef std::vector<Configuration*> ConfigurationList;
    typedef std::map<std::string, Configuration*> ConfigurationDict;
    
    Configuration strToConf(const char* str)
    {
        return Configuration(str);
    }
    Configuration intToConf(int i)
    {
        return Configuration(i);
    }
    Configuration uintToConf(unsigned int i)
    {
        return Configuration(i);
    }
    Configuration boolToConf(bool b)
    {
        return Configuration(b);
    }
    Configuration doubleToConf(double d)
    {
        return Configuration(d);
    }
%}

%pythoncode
%{
    import types
    
    def convertPyToConfiguration(obj):
        if type(obj) is types.StringType:
            return strToConf(obj)
        elif type(obj) is types.BooleanType:
            return boolToConf(obj)
        elif type(obj) is types.IntType:
            return intToConf(obj)
        elif type(obj) is types.LongType:
            return uintToConf(obj)
        elif type(obj) is types.FloatType:
            return doubleToConf(obj)
        elif type(obj) is types.ListType:
            conf = Configuration.createEmptyList()
            for element in obj:
                conf.insert(element)
            return conf
        elif type(obj) is types.DictType:
            conf = Configuration.createEmptyDict()
            for key in obj.keys():
                conf.insert(key,obj[key])
            return conf
        else:
            return obj
             
    def Configuration_insert(self,*args, **kwargs):
        if (len(args)==1):
            self.insertListEntryConfiguration(convertPyToConfiguration(args[0]))
        elif (len(args)==2):
            self.insertDictEntryConfiguration(args[0],convertPyToConfiguration(args[1]))
        else:
            raise Exception("too many arguments")
    setattr(Configuration,"insert",types.MethodType(Configuration_insert, None, Configuration))
    
    def Configuration_value(self):
        if self.getType()==ConfigurationType.NONE:
            return None
        elif self.getType()==ConfigurationType.BOOLEAN:
            return self.valueBoolean()
        elif self.getType()==ConfigurationType.INTEGER:
            return self.valueInteger()
        elif self.getType()==ConfigurationType.UINTEGER:
            return self.valueUnsignedInteger()
        elif self.getType()==ConfigurationType.FLOATINGPOINT:
            return self.valueDouble()
        elif self.getType()==ConfigurationType.STRING:
            return self.valueString()
        elif self.getType()==ConfigurationType.LIST:
            return self.valueList()
        elif self.getType()==ConfigurationType.MAP:
            return self.valueDict()
        else:
            return None
    setattr(Configuration,"value",types.MethodType(Configuration_value, None, Configuration))
    
                
        
%}



%include "Graph.hpp"
%template(ConstVariableList) std::vector<const Variable*>;


%include "Job.hpp"
%include "JobFactory.hpp"

%include "Algorithm.hpp"

%include "Node.hpp"
%include "Module.hpp"

%include "Variable.hpp"
%include "Scalar.hpp"
%include "NVector.hpp"
%include "LorentzVector.hpp"

%inline 
%{
   Scalar* Node_createScalar (Node* n, std::string name) 
   {
      return n->createVariable<Scalar>(name);
   }
   
   const Scalar* Node_getScalar (Node* n, std::string name)
   {
      return n->getVariable<Scalar>(name);
   }
%}

%pythoncode
%{
    import types
    setattr(Node,"createVariable_Scalar",types.MethodType(Node_createScalar, None, Node))
    setattr(Node,"getVariable_Scalar",types.MethodType(Node_getScalar, None, Node))
%}

