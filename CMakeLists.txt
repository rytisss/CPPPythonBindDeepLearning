cmake_minimum_required (VERSION 3.4)
project (CPPPythonBindExample)

if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-std=gnu++0x)
endif()

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
set(CMAKE_BUILD_PARALLEL_LEVEL)

add_subdirectory(main)
add_subdirectory(NetworkTrainer)
add_subdirectory(NetworkTrainerCS)
add_subdirectory(pybind11)