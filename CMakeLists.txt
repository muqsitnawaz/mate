cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

project(mate LANGUAGES CXX VERSION 0.0.1)
include(cmake/StandardProjectSettings.cmake)
include(cmake/PreventInSourceBuilds.cmake)

add_compile_definitions(FMT_HEADER_ONLY)

# Enable cache.
include(cmake/Cache.cmake)

# Enable standard warnings.
add_library(project_warnings INTERFACE)
include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

# Enable stanitizers.
include(cmake/Sanitizers.cmake)
enable_sanitizers(project_options)

# Enable static-analysis.
include(cmake/StaticAnalyzers.cmake)

# Set include dirs.
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(SYSTEM /usr/local/include)

# Basic.
add_executable(main src/main.cpp)
target_include_directories(main PRIVATE ${INCLUDE_DIR})
target_link_libraries(main PRIVATE project_warnings)

function(mate_add_test TESTNAME EXENAME FIRSTSOURCE)
    add_executable(${EXENAME} ${FIRSTSOURCE} ${ARGN})
    target_link_libraries(${EXENAME} gtest gtest_main)
    target_include_directories(${EXENAME} PRIVATE ${INCLUDE_DIR})
    add_test(${TESTNAME} ${EXENAME})
endfunction(mate_add_test)

if(MATE_TESTS OR CMAKE_BUILD_TYPE STREQUAL "Debug")
    enable_testing()
    include(GoogleTest)
    add_subdirectory(test)
endif()