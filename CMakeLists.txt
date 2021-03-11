cmake_minimum_required(VERSION 3.17)
project(adt C)

set(CMAKE_C_STANDARD 11)

add_executable(adt-demo main.c)

add_library(adt SHARED array_list.c linked_list.c stack.c)

set_target_properties(adt PROPERTIES PREFIX lib)

include_directories(${CMAKE_SOURCE_DIR})

target_link_libraries(adt-demo adt)