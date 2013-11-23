include_directories(${CMAKE_CURRENT_SOURCE_DIR}/P0_Sigma_sm_ddx_mummupbbx)
add_library(ZH-process
    P0_Sigma_sm_ddx_mummupbbx/CPPProcess.cc
)
target_link_libraries(ZH-process model-sm)
add_executable(check check_sa.cpp)
target_link_libraries(check model-sm ZH-process)
add_dependencies(check model-sm ZH-process)

