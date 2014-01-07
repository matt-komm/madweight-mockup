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
    int confToInt(Configuration conf)
    {
        return conf.value<int>();
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

