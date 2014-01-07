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
    Node.createScalar=types.MethodType(Node_createScalar, None, Node)
    Node.getScalar=types.MethodType(Node_getScalar, None, Node)
%}

