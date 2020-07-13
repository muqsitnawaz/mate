
cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(mate LANGUAGES CXX VERSION 0.0.1)

# Set standard version.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set compiler flags.
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_C_FLAGS_DEBUG "-stdlib=libc++ -Wall -Wextra -g")
    set(CMAKE_C_FLAGS_RELEASE "-O2")
    set(CMAKE_CXX_FLAGS_DEBUG ${CMAKE_C_FLAGS_DEBUG})
    set(CMAKE_CXX_FLAGS_RELEASE ${CMAKE_C_FLAGS_RELEASE})
endif ()

# Set default build type.
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif ()

# Set cmake paths.
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# Add compile time macros.
add_compile_definitions(FMT_HEADER_ONLY)

# Include libraries headers.
include_directories(/usr/local/include)

# Set include dirs.
set(INC_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Basic.
add_executable(main src/main.cpp)
target_include_directories(main PRIVATE ${INC_DIRS})

function(mate_add_test TESTNAME EXENAME FIRSTSOURCE)
    add_executable(${EXENAME} ${FIRSTSOURCE} ${ARGN})
    target_link_libraries(${EXENAME} gtest gtest_main)
    target_include_directories(${EXENAME} PRIVATE ${INC_DIRS})
    add_test(${TESTNAME} ${EXENAME})
endfunction(mate_add_test)

if(MATE_TESTS)
    enable_testing()
    include(GoogleTest)
    add_subdirectory(test)
endif()