set(CMAKE_CXX_FLAGS ${CXXCOMPILEFLAGS})

OPTION(ENABLE_LHCP "Build with VAMP interface" ON)

if (ENABLE_LHCP)
    #first build a helper library
    add_subdirectory(include/BOLlib)
    
    #build the complete lhcp library
    include_directories(
        include/LargeHadronColliderOlympicsClasses
        include/LesHouchesEventFileClasses
        include/LesHouchesEventFileClasses/FilterRuleClasses
        include/LesHouchesEventFileClasses/PreselectorClasses
        include/MassEigenstateCollectionClasses
        include/MassEigenstateCollectionClasses/MassSpectrumClasses
        include/MassEigenstateCollectionClasses/MassSpectrumClasses/ParticleSubsetClasses
        include/ParticleCodesAndDataClasses
        include/SlhaSpectrumPlottingClasses
        include/SusyLesHoucheAccordClasses
        include/SusyLesHoucheAccordClasses/BlockClasses
        include/SusyLesHoucheAccordClasses/BlockClasses/InterpreterClasses
        include
    )
    
    aux_source_directory(source/LargeHadronColliderOlympicsClasses LargeHadronColliderOlympicsClasses)
    aux_source_directory(source/LesHouchesEventFileClasses LesHouchesEventFileClasses)
    aux_source_directory(source/LesHouchesEventFileClasses/FilterRuleClasses FilterRuleClasses)
    aux_source_directory(source/LesHouchesEventFileClasses/PreselectorClasses PreselectorClasses)
    aux_source_directory(source/MassEigenstateCollectionClasses MassEigenstateCollectionClasses)
    aux_source_directory(source/MassEigenstateCollectionClasses/MassSpectrumClasses MassSpectrumClasses)
    aux_source_directory(source/MassEigenstateCollectionClasses/MassSpectrumClasses/ParticleSubsetClasses ParticleSubsetClasses)
    aux_source_directory(source/ParticleCodesAndDataClasses ParticleCodesAndDataClasses)
    aux_source_directory(source/SlhaSpectrumPlottingClasses SlhaSpectrumPlottingClasses)
    aux_source_directory(source/SusyLesHoucheAccordClasses SusyLesHoucheAccordClasses)
    aux_source_directory(source/SusyLesHoucheAccordClasses/BlockClasses BlockClasses)
    aux_source_directory(source/SusyLesHoucheAccordClasses/BlockClasses/InterpreterClasses InterpreterClasses)
    
    add_library(lhcp SHARED
        ${LargeHadronColliderOlympicsClasses}
        ${LesHouchesEventFileClasses}
        ${FilterRuleClasses}
        ${PreselectorClasses}
        ${MassEigenstateCollectionClasses}
        ${MassSpectrumClasses}
        ${ParticleSubsetClasses}
        ${ParticleCodesAndDataClasses}
        ${SlhaSpectrumPlottingClasses}
        ${SusyLesHoucheAccordClasses}
        ${BlockClasses}
        ${InterpreterClasses}
    )
    
    #integrate the tests from the lhco library
    add_executable(lhcp-lhco-test
        source/LhcoParserExample.cpp
    )
    target_link_libraries(lhcp-lhco-test lhcp BOLlib)
    add_dependencies(lhcp-lhco-test lhcp BOLlib)
    COPY_FILE_IF_CHANGED(${CMAKE_CURRENT_SOURCE_DIR}/testing/LhcoTest.txt ${CMAKE_CURRENT_BINARY_DIR}/LhcoTest.txt lhcp-lhco-test)
 
    #build the input modules
    include_directories(${PROJECT_SOURCE_DIR}/core)
    include_directories(${PROJECT_SOURCE_DIR}/plugins)
    include_directories(${PROJECT_SOURCE_DIR}/mem)
    add_library(lhcomodule MODULE
        LHCOInput.cpp
        initplugin.cpp
    )
    target_link_libraries(lhcomodule mw-core mw-plugins mw-mem lhcp BOLlib)
    add_dependencies(lhcomodule mw-core mw-plugins mw-mem lhcp BOLlib)    
endif(ENABLE_LHCP)
