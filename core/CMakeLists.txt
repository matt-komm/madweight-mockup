include_directories(${PROJECT_SOURCE_DIR}/core)

set(CMAKE_CXX_FLAGS ${CXXCOMPILEFLAGS})

add_library(mw-core SHARED
    
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

add_executable(test-core test.cpp)
target_link_libraries(test-core mw-core)
add_dependencies(test-core mw-core)
