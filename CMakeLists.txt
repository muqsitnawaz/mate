cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

project(mate LANGUAGES CXX VERSION 0.0.1 DESCRIPTION "Post-modern C++ library for abstract algebra")
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
add_library(project_options INTERFACE)
include(cmake/Sanitizers.cmake)
enable_sanitizers(project_options)

# Enable static-analysis.
include(cmake/StaticAnalyzers.cmake)

# Run conan.
include(cmake/Conan.cmake)
run_conan()

# Set include dirs.
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(SYSTEM /usr/local/include)

function(mate_add_test TESTNAME EXENAME FIRSTSOURCE)
    add_executable(${EXENAME} ${FIRSTSOURCE} ${ARGN})
    target_link_libraries(${EXENAME} project_warnings project_options gtest gtest_main)
    target_include_directories(${EXENAME} PRIVATE ${INCLUDE_DIR})
    add_test(NAME ${TESTNAME} COMMAND ${EXENAME})
endfunction(mate_add_test)

if(MATE_TESTS OR CMAKE_BUILD_TYPE STREQUAL "Debug")
    enable_testing()
    include(GoogleTest)
    add_subdirectory(test)
endif()