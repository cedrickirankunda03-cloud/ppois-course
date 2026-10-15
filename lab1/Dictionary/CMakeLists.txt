cmake_minimum_required(VERSION 3.15)

project(DictionaryProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
googletest
URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)

FetchContent_MakeAvailable(googletest)

add_executable(Dictionary
Dictionary.cpp
main.cpp
)

add_executable(DictionaryTests
Dictionary.cpp
DictionaryTests.cpp
)

target_link_libraries(DictionaryTests
GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(DictionaryTests)
