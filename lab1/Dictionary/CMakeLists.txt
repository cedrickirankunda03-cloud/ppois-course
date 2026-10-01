cmake_minimum_required(VERSION 3.15)

project(DictionaryProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(googletest)

add_executable(Dictionary
    Dictionary.cpp
    main.cpp
)

add_executable(DictionaryTest
    Dictionary.cpp
    DictionaryTest.cpp
)

target_link_libraries(DictionaryTest
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(DictionaryTest)