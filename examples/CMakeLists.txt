add_subdirectory(ME)

include_directories(${PROJECT_SOURCE_DIR}/core)
include_directories(${PROJECT_SOURCE_DIR}/mem)
include_directories(${PROJECT_SOURCE_DIR}/examples/ME/qcd_2j)
set(CMAKE_CXX_FLAGS ${CXXCOMPILEFLAGS})


add_executable(test-examples test.cpp)
target_link_libraries(test-examples mw-core mw-mem me-qcd_2j)
add_dependencies(test-examples mw-core mw-mem me-qcd_2j)
add_custom_command(TARGET test-examples POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/param_card.dat ${PROJECT_BINARY_DIR}/.) #cmake copy src and dest are rel. to source and build directories
