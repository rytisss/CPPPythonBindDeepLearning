cmake_minimum_required(VERSION 3.4)
project(bindingSample)

#add_subdirectory(../3rdParty/pybind11/)
include_directories(
	../3rdParty/pybind11/
 )

add_executable(bindingSample main.cpp)
target_link_libraries(bindingSample PRIVATE pybind11::embed) # need if we want interpreter