cmake_minimum_required(VERSION 3.16)
project(modbusrtu LANGUAGES C CXX)
find_package(libmodbus REQUIRED)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)


add_subdirectory(src)
