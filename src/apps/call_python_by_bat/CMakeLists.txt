# version requirement
cmake_minimum_required(VERSION 2.8)
GET_FILENAME_COMPONENT(project_name ${CMAKE_CURRENT_LIST_DIR} NAME)
# project information
if(${${project_name}})

link_libraries(
optimized ${PYTHON_DIR}/libs/python37.lib
)

file(GLOB_RECURSE Demo_SOURCES *.cpp)
file(GLOB_RECURSE Demo_HEADERS *.h)
ADD_EXECUTABLE(${project_name} ${Demo_SOURCES} ${Demo_HEADERS})
 
include_directories(${SOLUTION_DEPENDENCY_DIR})

FOREACH(subdir ${APP_INCLUDE_DIR})
	include_directories(${subdir})
ENDFOREACH()

target_link_libraries(${project_name} ${PROJECT_LIB_NAME})

set_target_properties(${project_name} PROPERTIES FOLDER apps)
endif()
