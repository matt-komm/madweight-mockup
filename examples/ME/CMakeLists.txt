macro(addME folder)
    include_directories(${folder}/${CMAKE_CURRENT_SOURCE_DIR})
    FILE(GLOB inFiles RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
        "${CMAKE_CURRENT_SOURCE_DIR}/${folder}/*.cc")
    add_library(me-${folder} SHARED ${inFiles})
    target_link_libraries(me-${folder} mw-core mw-mem)
    add_dependencies(me-${folder} mw-core mw-mem)
endmacro(addME)

addME(qcd_2j)
addME(semiTTbar)
