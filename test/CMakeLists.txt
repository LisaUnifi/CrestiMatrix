cmake_minimum_required(VERSION 3.7)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(SOURCE_TEST_FILES runAllTests.cpp MatrixTemplateTest.cpp SquareMatrixTemplateTest.cpp)
add_executable(runCrestiMatrixTests ${SOURCE_TEST_FILES})
target_link_libraries(runCrestiMatrixTests gtest gtest_main core)