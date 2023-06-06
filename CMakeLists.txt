cmake_minimum_required(VERSION 3.14)

# ---- Project ----
project(
  CSMUnits
  VERSION 1.0
  LANGUAGES CXX
)

# ---- Include guards ----
if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(
    FATAL_ERROR
      "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there."
  )
endif()

# ---- Add dependencies via CPM ----
# See https://github.com/TheLartians/CPM.cmake for more info
include(cmake/CPM.cmake)
CPMAddPackage("gh:onqtam/doctest@2.4.9")
CPMAddPackage("gh:TheLartians/Format.cmake@1.7.3")
CPMAddPackage("gh:TheLartians/PackageProject.cmake@1.8.0") # To make target installable
CPMAddPackage("gh:martinus/nanobench@4.3.11") # To make target installable

# ---- Create library ----
add_library(${PROJECT_NAME} INTERFACE)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20)

# Enforce standards conformance on MSVC
target_compile_options(${PROJECT_NAME} INTERFACE "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/permissive->")

target_include_directories(
  ${PROJECT_NAME} INTERFACE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                            $<INSTALL_INTERFACE:include/${PROJECT_NAME}-${PROJECT_VERSION}>
)

# ---- Create an installable target ----
# Allows users to install and find the library via `find_package()`. The location where the
# project's version header will be placed should match the project's regular header paths
string(TOLOWER ${PROJECT_NAME}/version.hpp VERSION_HEADER_LOCATION)

packageProject(
  NAME ${PROJECT_NAME}
  VERSION ${PROJECT_VERSION}
  NAMESPACE ${PROJECT_NAME}
  BINARY_DIR ${PROJECT_BINARY_DIR}
  INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include
  INCLUDE_DESTINATION include/${PROJECT_NAME}-${PROJECT_VERSION} # VERSION_HEADER
                                                                 # "${VERSION_HEADER_LOCATION}"
  COMPATIBILITY SameMajorVersion
)

# ---- Test Target ----
# Find test files
file(GLOB_RECURSE test_sources CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/test/source/*.cpp")

# Test Executable
add_executable(${PROJECT_NAME}_test ${test_sources})

target_link_libraries(${PROJECT_NAME}_test PRIVATE doctest::doctest nanobench)

target_include_directories(${PROJECT_NAME}_test PRIVATE "test" "include" ".")
# target_include_directories(${PROJECT_NAME}_test PRIVATE "test" "include"
# ${CMAKE_CURRENT_LIST_DIR})

set_property(
  TARGET ${PROJECT_NAME}_test
  # PROPERTY CMAKE_BUILD_TYPE Debug
  PROPERTY CMAKE_EXPORT_COMPILE_COMMANDS ON
)

# Compiler Properties for testing
target_compile_features(${PROJECT_NAME}_test PRIVATE cxx_std_20)
if(MSVC)
  target_compile_options(${PROJECT_NAME}_test PRIVATE /G /W4 /WX)
else()
  target_compile_options(${PROJECT_NAME}_test PRIVATE -g -Wall -Wextra -Wpedantic -Werror)
endif()

enable_testing()
include(${doctest_SOURCE_DIR}/scripts/cmake/doctest.cmake)
doctest_discover_tests(${PROJECT_NAME}_test)
