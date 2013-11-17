include_directories(${MW_ROOT}/core)
include_directories(${MW_ROOT}/mem)

set(CMAKE_CXX_FLAGS "-Wextra -Wall -pedantic -std=c++0x")

add_library(mw-mem SHARED
    TransferFunction.cpp
    MatrixElement.cpp
)
add_dependencies(mw-mem mw-core)

#add_executable(test-core test.cpp)
#target_link_libraries(test-core mw-core)
#add_dependencies(test-core mw-core)

