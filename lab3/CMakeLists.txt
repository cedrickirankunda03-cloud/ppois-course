
cmake_minimum_required(VERSION 3.20)

project(wms_lab3 LANGUAGES CXX)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Options
option(ENABLE_COVERAGE "Enable coverage instrumentation" OFF)
option(BUILD_TESTS "Build unit tests" ON)

# Coverage configuration
if(ENABLE_COVERAGE)
    add_compile_options(--coverage -fprofile-arcs -ftest-coverage -O0 -g)
    add_link_options(--coverage)
endif()

# Compiler warnings
add_compile_options(-Wall -Wextra -Wpedantic)

# Collect source files
file(GLOB_RECURSE WMS_SOURCES CONFIGURE_DEPENDS "src/*.cpp")

# Exclude main.cpp from the core library
list(REMOVE_ITEM WMS_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

# Core library
add_library(wms_core STATIC ${WMS_SOURCES})

target_include_directories(wms_core PUBLIC include)

# Main application
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")
    add_executable(wms_cli src/main.cpp)
    target_link_libraries(wms_cli PRIVATE wms_core)
endif()

# Unit tests
if(BUILD_TESTS)
    enable_testing()

    include(FetchContent)

    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
    )

    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    FetchContent_MakeAvailable(googletest)

    # Collect test files
    file(GLOB TEST_SOURCES CONFIGURE_DEPENDS "tests/*.cpp")

    # Test executable
    add_executable(wms_tests ${TEST_SOURCES})

    target_link_libraries(
        wms_tests
        PRIVATE
        wms_core
        GTest::gtest_main
    )

    # Automatically discover GoogleTest tests
    include(GoogleTest)

    gtest_discover_tests(wms_tests)
endif()
