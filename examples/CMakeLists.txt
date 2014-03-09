add_subdirectory(ME)

include_directories(${PROJECT_SOURCE_DIR}/core)
include_directories(${PROJECT_SOURCE_DIR}/mem)
include_directories(${PROJECT_SOURCE_DIR}/addons/graphviz)
include_directories(${PROJECT_SOURCE_DIR}/examples/ME/qcd_2j)
set(CMAKE_CXX_FLAGS ${CXXCOMPILEFLAGS})


add_executable(test-examples test.cpp)
target_link_libraries(test-examples mw-core mw-mem me-qcd_2j mw-graphviz graph gvc cdt)
add_dependencies(test-examples mw-core mw-mem me-qcd_2j mw-graphviz)

#TODO: Check file paths
COPY_FILE_IF_CHANGED(${CMAKE_CURRENT_SOURCE_DIR}/ME/param_card.dat ${CMAKE_CURRENT_BINARY_DIR}/param_card.dat test-examples)