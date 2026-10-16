cmake_minimum_required(VERSION 3.17)
project(EuroSerialCheck)

set(CMAKE_CXX_STANDARD 17)

add_executable(EuroSerialCheck main.cpp euroCheck.cpp euroCheck.h)
