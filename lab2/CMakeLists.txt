
cmake_minimum_required(VERSION 3.16)

project(DeanOfficeSystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)

option(ENABLE_COVERAGE "Enable GCC code coverage" OFF)

# Collect all implementation files.
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

# main.cpp belongs to the application, not the library.
list(FILTER SOURCES EXCLUDE REGEX "/main\\.cpp$")

# Core project library.
add_library(dean_office ${SOURCES})

target_include_directories(dean_office PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

# Command-line application.
add_executable(dean_office_app
    src/main.cpp
)

target_link_libraries(dean_office_app PRIVATE dean_office)

# Optional GCC coverage.
if(ENABLE_COVERAGE)
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        target_compile_options(dean_office PRIVATE
            --coverage
            -O0
            -g
        )

        target_link_options(dean_office PUBLIC
            --coverage
        )
    else()
        message(FATAL_ERROR "Coverage configuration currently supports GCC only.")
    endif()
endif()

# Tests remain a separate executable.
if(BUILD_TESTING)
    add_executable(dean_office_tests
        tests/Tests.cpp
    )

    target_link_libraries(dean_office_tests PRIVATE dean_office)

    add_test(
        NAME dean_office_tests
        COMMAND dean_office_tests
    )
endif()
