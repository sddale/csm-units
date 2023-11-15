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
CPMAddPackage("gh:TheLartians/Format.cmake@1.7.3")
CPMAddPackage("gh:TheLartians/PackageProject.cmake@1.8.0") # To make target
                                                           # installable

# # Define project options option(CSMUNITS_BUILD_TESTS "Set to ON to build
# tests" OFF) set(BUILD_TESTING OFF) set(DOCTEST_CONFIG_DISABLE OFF)

# ---- Create library ----
add_library(${PROJECT_NAME} INTERFACE)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 23)

# Enforce standards conformance on MSVC
target_compile_options(
  ${PROJECT_NAME} INTERFACE "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/permissive->"
)

target_include_directories(
  ${PROJECT_NAME}
  INTERFACE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
            $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
            $<INSTALL_INTERFACE:include/${PROJECT_NAME}-${PROJECT_VERSION}>
)

add_subdirectory(test)

# ---- Create an installable target ----
# Allows users to install and find the library via `find_package()`. The
# location where the project's version header will be placed should match the
# project's regular header paths
string(TOLOWER ${PROJECT_NAME}/version.hpp VERSION_HEADER_LOCATION)

packageProject(
  NAME ${PROJECT_NAME}
  VERSION ${PROJECT_VERSION}
  NAMESPACE ${PROJECT_NAME}
  BINARY_DIR ${PROJECT_BINARY_DIR}
  INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include
  INCLUDE_DESTINATION
    include/${PROJECT_NAME}-${PROJECT_VERSION} # VERSION_HEADER
                                               # "${VERSION_HEADER_LOCATION}"
  COMPATIBILITY SameMajorVersion
)
