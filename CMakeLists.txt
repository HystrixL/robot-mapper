cmake_minimum_required(VERSION 3.5)
project(robot_mapper LANGUAGES CXX)

add_library(${PROJECT_NAME} OBJECT ./robot_mapper.hpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
