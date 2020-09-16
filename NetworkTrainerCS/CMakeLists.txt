cmake_minimum_required(VERSION 3.4)
project(NetworkTrainerCS)

include_directories(
	../NetworkTrainer/
 )

add_library(NetworkTrainerCS SHARED
	NetworkTrainerCS.cpp
	NetworkTrainerCS.h
	NetworkTrainer.cpp
	NetworkTrainer.h
	TrainingEventsListener.cpp
	TrainingEventsListener.h)
	
target_link_libraries(NetworkTrainerCS PRIVATE pybind11::embed) # need if we want interpreter

set_property(TARGET NetworkTrainerCS PROPERTY VS_DOTNET_TARGET_FRAMEWORK_VERSION "v4.6.1")

set_target_properties(NetworkTrainerCS PROPERTIES COMMON_LANGUAGE_RUNTIME "")