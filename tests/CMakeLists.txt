OPTION(ENABLE_TEST "Build tests" OFF)

if (ENABLE_TEST)
    enable_testing()
    add_custom_target(build_and_test ${CMAKE_CTEST_COMMAND} -V)

    include_directories(${PROJECT_SOURCE_DIR}/core)
    include_directories(${PROJECT_SOURCE_DIR}/mem)
    include_directories(${PROJECT_SOURCE_DIR}/plugins)
    
    include_directories(${GTEST_ROOT}/include)

    macro(APPLYTEST name sourcefile libraries)
        add_executable(test-${name}
            ${sourcefile}
        )
        target_link_libraries(test-${name} ${libraries} gtest gtest_main pthread)
        add_test(test-${name}-gtest test-${name} --gtest_color=yes)
        #add_test(test-${name}-memtest valgrind --tool=memcheck --leak-check=summary ${CMAKE_CURRENT_BINARY_DIR}/test-${name} > /dev/null)
        add_dependencies(build_and_test test-${name} ${libraries} gtest gtest_main)

    endmacro(APPLYTEST)

    APPLYTEST(coretest test-core.cpp mw-core)

endif(ENABLE_TEST)

