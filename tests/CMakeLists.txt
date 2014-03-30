OPTION(ENABLE_TEST "Build tests" OFF)
OPTION(ENABLE_VERBOSE_TEST "verbose tests" OFF)

set(CMAKE_CXX_FLAGS ${CXXCOMPILEFLAGS})

if (ENABLE_TEST)
    enable_testing()
    if (ENABLE_VERBOSE_TEST)
        add_custom_target(build_and_test ${CMAKE_CTEST_COMMAND} -V)
    else (ENABLE_VERBOSE_TEST)
        add_custom_target(build_and_test ${CMAKE_CTEST_COMMAND})
    endif (ENABLE_VERBOSE_TEST)
    add_custom_target(pretest) #use for e.g. copying files before tests are run
    add_dependencies(build_and_test pretest)
    
    include_directories(${PROJECT_SOURCE_DIR}/core)
    include_directories(${PROJECT_SOURCE_DIR}/mem)
    include_directories(${PROJECT_SOURCE_DIR}/plugins)
    include_directories(${PROJECT_SOURCE_DIR}/tests)
    
    include_directories(${PROJECT_SOURCE_DIR}/external/gtest/include)
    
    add_library(sampleplugin MODULE sampleplugin.cpp)
    target_link_libraries(sampleplugin mw-core mw-plugins)

    macro(APPLYGTEST name sourcefile)
        add_executable(gtest-${name}
            ${sourcefile}
        )
        target_link_libraries(gtest-${name} ${ARGN} pthread gtest gtest_main)
        add_test(${name} gtest-${name} --gtest_color=yes)
        #add_test(memtest-${name} valgrind --tool=memcheck --leak-check=summary ${CMAKE_CURRENT_BINARY_DIR}/gtest-${name} > /dev/null)
        add_dependencies(build_and_test gtest-${name})
    endmacro(APPLYGTEST)
    
    ##### GTESTS #####
    APPLYGTEST(testcore test-core.cpp mw-core)
    APPLYGTEST(testplugins test-plugins.cpp mw-core mw-plugins)
    #####
    
    if (ENABLE_SWIG)
        message("enable swig testing")
        find_package(PythonInterp REQUIRED)
        macro(APPLYPYTHONTEST name unittestmodule dependency)
            add_test(NAME ${name} COMMAND ${PYTHON_EXECUTABLE} -m unittest -v ${unittestmodule})
            set_tests_properties(${name} PROPERTIES DEPENDS ${dependency})
            COPY_FILE_IF_CHANGED(${CMAKE_CURRENT_SOURCE_DIR}/${unittestmodule}.py ${CMAKE_CURRENT_BINARY_DIR}/${unittestmodule}.py pretest)           
            add_dependencies(build_and_test ${name})
        endmacro(APPLYPYTHONTEST)
        
        ##### PYTHONTESTS #####
        APPLYPYTHONTEST(pytestcore testpycore mwcore)
        APPLYPYTHONTEST(pytestplugins testpyplugins mwplugins)
        #####
        
    endif(ENABLE_SWIG)
    
    
    

endif(ENABLE_TEST)

