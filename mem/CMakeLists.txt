include_directories(${MW_ROOT}/core)
include_directories(${MW_ROOT}/mem)

set(CMAKE_CXX_FLAGS ${CXXCOMPILEFLAGS})

add_library(mw-mem SHARED
    TransferFunction.cpp
    MatrixElement.cpp
)
add_dependencies(mw-mem mw-core)

add_executable(test-mem test.cpp)
target_link_libraries(test-mem mw-core)
add_dependencies(test-mem mw-core)

