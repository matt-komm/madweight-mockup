include_directories(${MW_ROOT}/core)

set(CMAKE_CXX_FLAGS "-Wextra -Wall -pedantic -std=c++0x")

add_library(mw-core SHARED
    
    Variable.cpp
    NVector.cpp
    Scalar.cpp
    VariableArray.cpp
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

