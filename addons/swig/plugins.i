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

%module(directors="1") mwplugins
%{
    #include "Plugin.hpp"
    #include "PluginFactory.hpp"
    #include "Module.hpp"
    #include "Algorithm.hpp"
%}

%include "Plugin.hpp"
%include "PluginFactory.hpp"
%template(StringList) std::vector<std::string>;

%template(getPluginModule) PluginFactory::getPlugin<Module>;
%template(getPluginAlgorithm) PluginFactory::getPlugin<Algorithm>;

%template(PluginModule) Plugin<Module>;
%template(PluginAlgorithm) Plugin<Algorithm>;

%inline
%{
%}

%pythoncode
%{
%}

