
cmake_minimum_required(VERSION 3.15)

project(DictionaryProject LANGUAGES CXX)

# Enable testing
enable_testing()

# C++ settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Download GoogleTest using Git
include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG f8d7d77c06936315286eb55f8de22cd23c188571
    GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(googletest)

# Copy dictionary.txt into the build directory
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/dictionary.txt"
    "${CMAKE_CURRENT_BINARY_DIR}/dictionary.txt"
    COPYONLY
)

# Dictionary application
add_executable(Dictionary
    Dictionary.cpp
    main.cpp
)

# Dictionary unit tests
add_executable(DictionaryTests
    Dictionary.cpp
    DictionaryTests.cpp
)

# Link GoogleTest
target_link_libraries(DictionaryTests
    PRIVATE
    GTest::gtest_main
)

# Register GoogleTest tests with CTest
include(GoogleTest)
gtest_discover_tests(DictionaryTests)
