cmake_minimum_required(VERSION 3.16)
project(Vector)

set(CMAKE_CXX_STANDARD 11)

add_executable(Vector Vector.h VectorImpl.h Vector.cpp VectorTest.cc)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()

target_link_libraries(
    Vector
    ${GTEST_LIBRARIES}
    gtest_main
    pthread
)

gtest_discover_tests(Vector)