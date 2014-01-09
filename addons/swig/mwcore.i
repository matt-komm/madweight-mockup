//%module(directors="1", package="mw") core

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


%include "Configuration.hpp"
%inline
%{
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
    
    def convertPyToConfiguration(self,obj):
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
            for element in obj:
                pass
            #listToConf(obj)
        elif type(obj) is types.DictType:
            for key in obj.keys():
                pass
            #dictToConf(obj)
        else:
            return obj
             
    #this will call the original class method and convert the PyObjects to Configuration
    def Configuration_insert(self,name,obj):
        self.insert(name,convertPyToConfiguration(obj))
    
    setattr(Configuration,"insert",types.MethodType(Configuration_insert, None, Configuration))
%}



%include "Graph.hpp"

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

