include_directories(${PROJECT_SOURCE_DIR}/core)
include_directories(${PROJECT_SOURCE_DIR}/plugins)
include_directories(${PROJECT_SOURCE_DIR}/mem)

set(CMAKE_CXX_FLAGS ${CXXCOMPILEFLAGS})

add_library(mw-mem SHARED
    TransferFunction.cpp
    MatrixElement.cpp
    MomentumMapper.cpp
)
add_dependencies(mw-mem mw-core)

add_executable(test-mem test.cpp)
target_link_libraries(test-mem mw-core)
add_dependencies(test-mem mw-core)


