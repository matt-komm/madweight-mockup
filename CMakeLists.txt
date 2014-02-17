cmake_minimum_required (VERSION 2.6)


project (madweight-mockup)

#set(CXXCOMPILEFLAGS "-std=c++0x")
set(CXXCOMPILEFLAGS "-Wextra -Wall -pedantic -std=c++0x")

MACRO(COPY_FILE_IF_CHANGED in_file out_file target)
    IF(${in_file} IS_NEWER_THAN ${out_file})    
        #message("Copying file: ${in_file} to: ${out_file}")
    	ADD_CUSTOM_COMMAND (
    		TARGET     ${target}
    		POST_BUILD
    		COMMAND    ${CMAKE_COMMAND}
    		ARGS       -E copy ${in_file} ${out_file}
    	)
	ENDIF(${in_file} IS_NEWER_THAN ${out_file})
ENDMACRO(COPY_FILE_IF_CHANGED)

OPTION(BUILD_WITH_COVERAGE "Build with coverage analysis support" OFF)
if(BUILD_WITH_COVERAGE)
    if(CMAKE_COMPILER_IS_GNUCC)
        message("running coverage testing")
        set(CMAKE_C_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
        set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage -lgcov")
        #set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -fprofile-arcs -ftest-coverage -lgcov")
        add_custom_target(generatecoverage COMMAND ${CMAKE_CURRENT_BINARY_DIR}/core/test-core)
        add_dependencies(generatecoverage test-core)
        add_custom_target(createcoverage COMMAND lcov -d ${CMAKE_CURRENT_BINARY_DIR}/core -c -o ${CMAKE_CURRENT_BINARY_DIR}/coverage.info)
        add_dependencies(createcoverage generatecoverage)
        add_custom_target(coveragesummary COMMAND genhtml ${CMAKE_CURRENT_BINARY_DIR}/coverage.info --output-directory ${CMAKE_BINARY_SOURCE_DIR}/coverage)
        add_dependencies(coveragesummary createcoverage)
        
    
    endif(CMAKE_COMPILER_IS_GNUCC)
endif(BUILD_WITH_COVERAGE)

add_subdirectory(external)
add_subdirectory(core)
add_subdirectory(plugins)
add_subdirectory(mem)
add_subdirectory(addons)
add_subdirectory(examples)
add_subdirectory(tests)
