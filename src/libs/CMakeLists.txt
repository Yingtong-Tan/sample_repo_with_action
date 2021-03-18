# version requirement
cmake_minimum_required(VERSION 2.8)

SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})

set(SEARCH_INCLUDE_DIR ${SUBDIRS} CACHE INTERNAL "a include dir")