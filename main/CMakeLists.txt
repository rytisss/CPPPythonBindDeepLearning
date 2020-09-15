cmake_minimum_required(VERSION 3.4)
project(bindingSample)

#add_subdirectory(../3rdParty/pybind11/)
include_directories(
	../3rdParty/pybind11/
 )

add_executable(bindingSample main.cpp)
target_link_libraries(bindingSample PRIVATE pybind11::embed) # need if we want interpreter

file(TO_CMAKE_PATH $<TARGET_FILE_DIR:bindingSample>// target_path)
add_custom_command(TARGET bindingSample POST_BUILD COMMAND ${CMAKE_COMMAND} ARGS -E copy_directory  
	${CMAKE_SOURCE_DIR}//modules//
	${target_path})

add_custom_command(TARGET bindingSample POST_BUILD COMMAND ${CMAKE_COMMAND} ARGS -E copy_directory  
	${CMAKE_SOURCE_DIR}//RoadPavementSegmentation//
	${target_path}//)

add_custom_command(TARGET bindingSample POST_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory ${target_path}//RoadPavementSegmentation//)
add_custom_command(TARGET bindingSample POST_BUILD COMMAND ${CMAKE_COMMAND} ARGS -E copy_directory  
	${CMAKE_SOURCE_DIR}//RoadPavementSegmentation//
	${target_path}//RoadPavementSegmentation//)