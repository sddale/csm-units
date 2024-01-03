#include <doctest/doctest.h>

#include <csm_units/concepts.hpp>
#include <source/csm_units/definition.hpp>
#include <source/csm_units/exponents.hpp>
#include <source/csm_units/unit.hpp>
// #include <csm_units/units.hpp>
#include <gcem.hpp>

#ifndef CSMUNITS_VALUE_TYPE
#define CSMUNITS_VALUE_TYPE double
#endif

namespace csm_units::test {

namespace definition {
using Rankine =
    Definition<Exponents<0, 0, 0, 0, 1, 0, 0>, std::ratio<1>, std::ratio<1>,
               std::ratio<1>, std::ratio<1>, std::ratio<9, 5>>;

using SquareRankine =
    Definition<Exponents<0, 0, 0, 0, 2, 0, 0>, std::ratio<1>, std::ratio<1>,
               std::ratio<1>, std::ratio<1>, std::ratio<9, 5>>;

using Kelvin = Definition<Exponents<0, 0, 0, 0, 1, 0, 0>>;

}  // namespace definition

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Size") {
  constexpr auto R =  // NOLINT(readability-identifier-length)
      definition::Rankine();

  using Rankine = Unit<decltype(R), double>;
  using Kelvin = Unit<definition::Kelvin, double>;
  using Celsius = Unit<definition::Kelvin, double, std::ratio<5463, 20>>;
  using Fahrenheit = Unit<decltype(R), double, std::ratio<45967, 180>>;
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