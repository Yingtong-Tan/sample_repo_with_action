# version requirement
cmake_minimum_required(VERSION 2.8)
GET_FILENAME_COMPONENT(project_name ${CMAKE_CURRENT_LIST_DIR} NAME)
# project information
if(${${project_name}})

# project information
project(${project_name})

# compile as a static library
file(GLOB_RECURSE Demo_SOURCES *.cpp)
file(GLOB_RECURSE Demo_HEADERS *.h)
add_library(${project_name} STATIC ${Demo_SOURCES} ${Demo_HEADERS}) 

# set folder in solution
set_target_properties(${project_name} PROPERTIES FOLDER libs)
endif()