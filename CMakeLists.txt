cmake_minimum_required (VERSION 2.6)

ADD_DEFINITIONS(-std=c++11)

set (PROJECT CGIServer)

project (${PROJECT})

file( GLOB SOURCES *.cpp )
file( GLOB HEADERS *.h )

find_package (Threads)

add_executable (${PROJECT} ${HEADERS} ${SOURCES})

target_link_libraries (${PROJECT} ${CMAKE_THREAD_LIBS_INIT})