PROJECT(c_python_api CXX)
# version requirement
cmake_minimum_required(VERSION 2.8)
# do not change
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(BUILD build)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${BUILD_DIR}/lib )
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${BUILD_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${BUILD_DIR}/bin )
set(CMAKE_CONFIGURATION_TYPES Debug Release CACHE STRING INTERNAL FORCE )
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2 /MT /W2 /Oi /bigobj")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /bigobj /MDd")

MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
      LIST(APPEND dirlist ${curdir}/${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()

MACRO(SUBDIRLIST_RELATIVE result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
      LIST(APPEND dirlist ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()

add_subdirectory(src)

SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR}/src)
FOREACH(subdir ${SUBDIRS})
  ADD_SUBDIRECTORY(${subdir})
ENDFOREACH()

set(PYTHON_DIR C:/tools/Anaconda3/envs/py37_opcv CACHE INTERNAL "solution python install dir")

set(SOLUTION_DEPENDENCY_DIR ${PYTHON_DIR}/include CACHE INTERNAL "solution denpendency dir")
set(SOLUTION_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src CACHE INTERNAL "solution source dir")




