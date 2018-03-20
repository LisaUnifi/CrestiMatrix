cmake_minimum_required(VERSION 3.6)
project(CrestiMatrix)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp MatrixTemplate.h SquareMatrixTemplate.h)
add_executable(CrestiMatrix ${SOURCE_FILES})