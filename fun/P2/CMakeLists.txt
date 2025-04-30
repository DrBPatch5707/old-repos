cmake_minimum_required(VERSION 3.0)

project(p2)

add_executable(p2 main.cpp)

install(TARGETS p2 RUNTIME DESTINATION bin)
