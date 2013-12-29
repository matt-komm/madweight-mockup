include_directories(${PROJECT_SOURCE_DIR}/core)
include_directories(${PROJECT_SOURCE_DIR}/plugins)

set(CMAKE_CXX_FLAGS ${CXXCOMPILEFLAGS})

#add_library(mw-plugins SHARED
#    Plugin.cpp
#)
#add_dependencies(mw-plugins mw-core)

add_library(testplugin MODULE
    testplugin.cpp
)
target_link_libraries(testplugin mw-core)
add_dependencies(testplugin mw-core)

add_executable(test-plugins testplugin.cpp test.cpp)
target_link_libraries(test-plugins mw-core dl)
add_dependencies(test-plugins mw-plugins)

