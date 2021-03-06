set(CMAKE_CXX_FLAGS ${CXXCOMPILEFLAGS})

OPTION(ENABLE_GRAPHVIZ "Build with GraphViz support" ON)
if (ENABLE_GRAPHVIZ)
    SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}")
    find_package(GRAPHVIZ)
    if (NOT GRAPHVIZ_FOUND)
        message("GRAPHVIZ not found - plugin disabled")
        set(ENABLE_GRAPHVIZ OFF)
    endif (NOT GRAPHVIZ_FOUND)
endif (ENABLE_GRAPHVIZ)

if (ENABLE_GRAPHVIZ)
    include_directories(${PROJECT_SOURCE_DIR}/core)
    include_directories(${PROJECT_SOURCE_DIR}/addons/graphviz)
    link_directories(${GRAPHVIZ_LIBRARIES})
    add_library(mw-graphviz SHARED GraphViz.cpp)
    add_dependencies(mw-graphviz mw-core)
    
    add_executable(test-graphviz test.cpp)
    target_link_libraries(test-graphviz mw-core mw-graphviz graph gvc cdt)
    add_dependencies(test-graphviz mw-core mw-graph)
endif(ENABLE_GRAPHVIZ)
