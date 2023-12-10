# include(../cmake/CPM.cmake)
CPMAddPackage("gh:onqtam/doctest@2.4.9")

add_executable(
  ${PROJECT_NAME}_test
  source/converter.cpp
  # source/demonstration.cpp
  # source/exponents.cpp
  # source/literal.cpp
  source/main.cpp
  # source/unit.cpp
  # source/unitbase.cpp
  # source/conversion.cpp
)
target_link_libraries(
  ${PROJECT_NAME}_test PRIVATE doctest::doctest CSMUnits::CSMUnits gcem
)
set_target_properties(${PROJECT_NAME}_test PROPERTIES CXX_STANDARD 23)

set_property(
  TARGET ${PROJECT_NAME}_test
  PROPERTY CMAKE_BUILD_TYPE Debug
  PROPERTY CMAKE_EXPORT_COMPILE_COMMANDS ON
)

# Compiler Properties for testing
target_compile_features(${PROJECT_NAME}_test PRIVATE cxx_std_23)
if(MSVC)
  target_compile_options(${PROJECT_NAME}_test PRIVATE /bigobj /W4 /WX)
else()
  target_compile_options(
    ${PROJECT_NAME}_test PRIVATE -g -Wall -Wextra -Wpedantic -Werror -std=c++2b
  )
endif()

enable_testing()

include(${doctest_SOURCE_DIR}/scripts/cmake/doctest.cmake)
doctest_discover_tests(${PROJECT_NAME}_test)
