cmake_minimum_required(VERSION 3.22)
project(mad_pong)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(mad_pong main.cpp Engine/Engine.cpp Engine/Engine.h)
target_link_libraries(mad_pong sfml-graphics sfml-audio)
