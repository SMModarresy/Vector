cmake_minimum_required(VERSION 3.24)
project(Vector)

set(CMAKE_CXX_STANDARD 11)

add_executable(Vector Vector.cpp Vector.h VectorTest.cc VectorImpl.h)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/15460959cbbfa20e66ef0b5ab497367e47fc0a04.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

target_link_libraries(
    Vector
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(Vector)