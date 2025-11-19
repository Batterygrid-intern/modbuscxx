cmake_minimum_required(VERSION 3.16)
project(modbuscxx VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Option to build shared library (default is static)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# Only build examples/tests if this is the main project
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    option(MODBUSCXX_BUILD_EXAMPLES "Build examples" ON)
else()
    option(MODBUSCXX_BUILD_EXAMPLES "Build examples" OFF)
endif()

add_subdirectory(src)
