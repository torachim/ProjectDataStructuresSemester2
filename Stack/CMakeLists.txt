cmake_minimum_required(VERSION 3.16)
project(ProjectAlpha VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)
add_executable(ProjectAlpha examples/stackmain.cpp)

include(FetchContent)
if(CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
        cmake_policy(SET CMPO135 NEW)
endif()

FetchContent_Declare(
    googletest 
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)
include(GoogleTest)

enable_testing()

add_executable(stackTest tests/stackTest.cpp)
target_link_libraries(stackTest GTest::gtest_main)
gtest_discover_tests(stackTest)


#cmake -S . -B build && cmake --build build
#./build/ProjectAlpha

