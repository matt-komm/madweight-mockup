include_directories(${PROJECT_SOURCE_DIR}/core)
include_directories(${PROJECT_SOURCE_DIR}/plugins)

set(CMAKE_CXX_FLAGS ${CXXCOMPILEFLAGS})

add_library(mw-plugins SHARED
    PluginFactory.cpp
)
add_dependencies(mw-plugins mw-core)

add_library(testplugin MODULE
    testplugin.cpp
)

target_link_libraries(testplugin mw-core mw-plugins)
add_dependencies(testplugin mw-plugins)

add_executable(test-plugins test.cpp)
target_link_libraries(test-plugins mw-core mw-plugins dl)
add_dependencies(test-plugins mw-plugins)

