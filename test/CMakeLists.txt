# include(../cmake/CPM.cmake)
CPMAddPackage("gh:onqtam/doctest@2.4.9")

add_executable(
  ${PROJECT_NAME}_test
  source/dimension.cpp
  source/math.cpp
  # source/demonstration.cpp
  source/main.cpp
  source/unit.cpp
  source/arithmetic.cpp
  source/comparison.cpp
  source/definition.cpp
  source/size.cpp
  source/named_units/absorbed_dose.cpp
  source/named_units/acceleration.cpp
  source/named_units/activity.cpp
  source/named_units/amount.cpp
  source/named_units/area.cpp
  source/named_units/capacitance.cpp
  source/named_units/catalytic_activity.cpp
  source/named_units/conductance.cpp
  source/named_units/density.cpp
  source/named_units/dose_equivalent.cpp
  source/named_units/electric_charge.cpp
  source/named_units/electric_current.cpp
  source/named_units/energy.cpp
  source/named_units/force.cpp
  source/named_units/frequency.cpp
  source/named_units/heat_capacity.cpp
  source/named_units/illuminance.cpp
  source/named_units/inductance.cpp
  source/named_units/length.cpp
  source/named_units/luminosity.cpp
  source/named_units/luminous_flux.cpp
  source/named_units/magnetic_flux.cpp
  source/named_units/magnetic_flux_density.cpp
  source/named_units/mass.cpp
  source/named_units/molar_energy.cpp
  source/named_units/molar_heat_capacity.cpp
  source/named_units/molar_mass.cpp
  source/named_units/molar_volume.cpp
  source/named_units/momentum.cpp
  source/named_units/potential_electromotive_force.cpp
  source/named_units/power.cpp
  source/named_units/pressure.cpp
  source/named_units/resistance.cpp
  source/named_units/solubility_parameter.cpp
  source/named_units/specific_heat_capacity.cpp
  source/named_units/temperature.cpp
  source/named_units/time.cpp
  source/named_units/velocity.cpp
  source/named_units/volume.cpp
)
target_link_libraries(
  ${PROJECT_NAME}_test PRIVATE doctest::doctest CSMUnits::CSMUnits
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
