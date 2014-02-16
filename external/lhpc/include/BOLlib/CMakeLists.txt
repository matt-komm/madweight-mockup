set(CMAKE_CXX_FLAGS ${CXXCOMPILEFLAGS})

include_directories(include)
add_library(BOLlib SHARED
    source/ArgumentParser.cpp
    source/AsciiXmlParser.cpp
    source/BalancedPartitionCandidate.cpp
    source/BasicObserved.cpp
    source/BasicObserver.cpp
    source/BasicTimer.cpp
    source/CommentedTextParser.cpp
    source/FilePlaceholderManager.cpp
    source/InputFileToOutputFileClaimer.cpp
    source/StringParser.cpp
    source/TwoDimensionalDataPlotter.cpp
    source/UsefulStuff.cpp
    source/WaitingOnSubprocessExecutor.cpp
)
