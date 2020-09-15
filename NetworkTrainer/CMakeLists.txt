cmake_minimum_required(VERSION 3.4)
project(NetworkTrainer)

include_directories(
	../pybind11/
 )

add_definitions( -DNETWORKTRAINER_EXPORT )

add_library(NetworkTrainer SHARED
	NetworkTrainer.cpp
	NetworkTrainer.h
	TrainingEventsListener.cpp
	TrainingEventsListener.h)
	
target_link_libraries(NetworkTrainer PRIVATE pybind11::embed) # need if we want interpreter