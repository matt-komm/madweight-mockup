add_subdirectory(ME)

include_directories(${MW_ROOT}/core)
include_directories(${MW_ROOT}/mem)
include_directories(${MW_ROOT}/examples/ME/qcd_2j)
set(CMAKE_CXX_FLAGS ${CXXCOMPILEFLAGS})


add_executable(test-examples test.cpp)
target_link_libraries(test-examples mw-core mw-mem me-qcd_2j)
add_dependencies(test-examples mw-core mw-mem me-qcd_2j)
file(COPY param_card.dat DESTINATION .) #cmake copy src and dest are rel. to source and build directories
