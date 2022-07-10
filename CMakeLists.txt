cmake_minimum_required(VERSION 3.0)
project(get_private)

add_library(get_private INTERFACE)
target_include_directories(get_private INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(test test.cpp)
target_link_libraries(test PRIVATE get_private)
