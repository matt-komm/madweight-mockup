include_directories(${PROJECT_SOURCE_DIR}/core)
include_directories(${PROJECT_SOURCE_DIR}/plugins)

set(CMAKE_CXX_FLAGS ${CXXCOMPILEFLAGS})

add_library(mw-plugins SHARED
    PluginFactory.cpp
)
target_link_libraries(mw-plugins dl)
add_dependencies(mw-plugins mw-core)


