cmake_minimum_required(VERSION 3.14)

# ---- Project ----
project(CSMUnitsTests LANGUAGES CXX)

# ---- Include guards ----
if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(
    FATAL_ERROR
      "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there."
  )
endif()

# Import tools
include(../cmake/tools.cmake)

# ---- Add dependencies via CPM ----
# See https://github.com/TheLartians/CPM.cmake for more info
include(../cmake/CPM.cmake)
CPMAddPackage("gh:onqtam/doctest@2.4.9")
CPMAddPackage("gh:TheLartians/Format.cmake@1.7.3")
CPMAddPackage("gh:sddale/csm-units@1.1.0")

# ---- Create binary ----

file(GLOB sources CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)
add_executable(${PROJECT_NAME} ${sources})
target_link_libraries(${PROJECT_NAME} doctest::doctest CSMUnits::CSMUnits)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20)

# enable compiler warnings if(NOT TEST_INSTALLED_VERSION)
# if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES
# "GNU") target_compile_options(Greeter PUBLIC -Wall -Wpedantic -Wextra -Werror)
# elseif(MSVC) target_compile_options(Greeter PUBLIC /W4 /WX)
# target_compile_definitions(${PROJECT_NAME} PUBLIC
# DOCTEST_CONFIG_USE_STD_HEADERS) endif() endif()

enable_testing()

include(${doctest_SOURCE_DIR}/scripts/cmake/doctest.cmake)
doctest_discover_tests(${PROJECT_NAME})
