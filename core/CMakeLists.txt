include_directories(${PROJECT_SOURCE_DIR}/core)

set(CMAKE_CXX_FLAGS ${CXXCOMPILEFLAGS})

add_library(mw-core SHARED
    defs.cpp
    Variable.cpp
    NVector.cpp
    Scalar.cpp
    LorentzVector.cpp
    Node.cpp
    Algorithm.cpp
    Graph.cpp
    Configuration.cpp
    Module.cpp
    Job.cpp
    JobFactory.cpp
)

