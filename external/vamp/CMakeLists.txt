OPTION(ENABLE_VAMP "Build with VAMP interface" ON)

if (ENABLE_VAMP)
    ENABLE_LANGUAGE(Fortran)
    SET (CMAKE_Fortran_COMPILER  gfortran)
    set(CMAKE_CXX_FLAGS ${CXXCOMPILEFLAGS})

    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
    add_library(vamp 
        src/divisions.f90
        src/exceptions.f90
        src/histograms.f90
        src/iso_fortran_env_stub.f90
        src/kinds.f90
        src/linalg.f90
        #src/mpi90.f90
        src/products.f90
        src/specfun.f90
        src/tao52_random_numbers.f90
        src/tao_random_numbers.f90
        src/utils.f90
        src/vamp.f90
        #src/vampi.f90
        src/vamp_stat.f90
    )

    include_directories(${PROJECT_SOURCE_DIR}/core)
    include_directories(${PROJECT_SOURCE_DIR}/external/vamp ${CMAKE_CURRENT_BINARY_DIR})
    add_library(mw-vamp SHARED interface.f90 VAMPIntegrator.cpp)
    link_directories(${VAMP_LIBRARIES})
    target_link_libraries(mw-vamp mw-core )
    add_dependencies(mw-vamp mw-core vamp)

    add_executable(test-vamp test.cpp)
    target_link_libraries(test-vamp mw-vamp mw-core vamp)
    add_dependencies(test-vamp mw-vamp vamp)

endif(ENABLE_VAMP)
