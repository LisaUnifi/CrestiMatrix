cmake_minimum_required(VERSION 3.7)
project(CrestiMatrix)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(test)

set(SOURCE_FILES main.cpp MatrixTemplate.h SquareMatrixTemplate.h FactoryMatrixTemplate.h FunctionMatrixTemplate.h)
add_executable(CrestiMatrix main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(CrestiMatrix core)