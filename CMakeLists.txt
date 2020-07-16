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
include_directories(SYSTEM /usr/local/include)

# Basic.
add_executable(main src/main.cpp)
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(main PRIVATE project_warnings)

function(mate_add_test TESTNAME EXENAME FIRSTSOURCE)
    add_executable(${EXENAME} ${FIRSTSOURCE} ${ARGN})
    target_include_directories(${EXENAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
    target_link_libraries(${EXENAME} gtest gtest_main)
    add_test(${TESTNAME} ${EXENAME})
endfunction(mate_add_test)

if(MATE_TESTS)
    enable_testing()
    include(GoogleTest)
    add_subdirectory(test)
endif()