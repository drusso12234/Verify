cmake_minimum_required(VERSION 3.13)
project(verify0_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(verify0_1 main.cpp dataObject.cpp dataObject.h dataObjectNode.h data.h tableManager.h tableManager.cpp)