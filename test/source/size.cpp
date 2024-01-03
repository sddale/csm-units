#include <doctest/doctest.h>

#include <csm_units/concepts.hpp>
#include <csm_units/temperature.hpp>
#include <gcem.hpp>
#include <source/csm_units/definition.hpp>
#include <source/csm_units/dimension.hpp>
#include <source/csm_units/unit.hpp>

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Size") {
  TEST_CASE("Default") {
    static_assert(sizeof(CSMUNITS_VALUE_TYPE) ==
                  sizeof(Unit<definition::Kelvin>));
  }
  TEST_CASE("Template initialization") {
    static_assert(sizeof(double) == sizeof(Unit<definition::Kelvin, double>));
    static_assert(sizeof(float) == sizeof(Unit<definition::Kelvin, float>));
  }
  TEST_CASE("Operator*") {
    static_assert(sizeof(double) ==
                  sizeof(decltype(Unit<definition::Kelvin, double>() *
                                  Unit<definition::Kelvin, float>())));
    static_assert(sizeof(double) ==
                  sizeof(decltype(Unit<definition::Kelvin, float>() *
                                  Unit<definition::Kelvin, double>())));
  }
  TEST_CASE("Operator/") {
    static_assert(sizeof(double) ==
                  sizeof(decltype(Unit<definition::Kelvin, double>() /
                                  Unit<definition::Kelvin, float>())));
    static_assert(sizeof(double) ==
                  sizeof(decltype(Unit<definition::Kelvin, float>() /
                                  Unit<definition::Kelvin, double>())));
  }
  TEST_CASE("Operator-") {
    static_assert(sizeof(double) ==
                  sizeof(decltype(Unit<definition::Kelvin, double>() -
                                  Unit<definition::Kelvin, float>())));
    static_assert(sizeof(float) ==
                  sizeof(decltype(Unit<definition::Kelvin, float>() -
                                  Unit<definition::Kelvin, double>())));
  }
  TEST_CASE("Operator+") {
    static_assert(sizeof(double) ==
                  sizeof(decltype(Unit<definition::Kelvin, double>() +
                                  Unit<definition::Kelvin, float>())));
    static_assert(sizeof(float) ==
                  sizeof(decltype(Unit<definition::Kelvin, float>() +
                                  Unit<definition::Kelvin, double>())));
  }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test