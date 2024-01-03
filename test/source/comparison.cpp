#include <doctest/doctest.h>

#include <csm_units/concepts.hpp>
#include <gcem.hpp>
#include <source/csm_units/definition.hpp>
#include <source/csm_units/dimension.hpp>
#include <source/csm_units/unit.hpp>

#include "common.hpp"

namespace csm_units::test {

namespace definition {
using Rankine =
    Definition<Dimension<0, 0, 0, 0, 1, 0, 0>, std::ratio<1>, std::ratio<1>,
               std::ratio<1>, std::ratio<1>, std::ratio<9, 5>>;

using Kelvin = Definition<Dimension<0, 0, 0, 0, 1, 0, 0>>;

}  // namespace definition

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Comparison") {
  constexpr auto R =  // NOLINT(readability-identifier-length)
      definition::Rankine();

  using Rankine = Unit<decltype(R), double>;
  using Kelvin = Unit<definition::Kelvin, double>;
  using Celsius = Unit<definition::Kelvin, double, std::ratio<5463, 20>>;
  using Fahrenheit = Unit<decltype(R), double, std::ratio<45967, 180>>;
  TEST_CASE("Operator==") {
    static_assert(Rankine(100.) == Kelvin(100. * 5 / 9));
    CHECK_UNIT_EQ(Fahrenheit(100.), Rankine(100 + 459.67));
    CHECK_DBL_EQ(Fahrenheit(100).data, Celsius(37.7778).data);
  }
  TEST_CASE("Operator!=") {
    static_assert(Rankine(100.) != Kelvin(101. * 5 / 9));
    static_assert(Fahrenheit(90.) != Rankine(100 + 459.67));
    CHECK(Fahrenheit(101).data != doctest::Approx(Celsius(37.7778).data));
  }
  TEST_CASE("Operator<=") {
    static_assert(Rankine(100.) <= Kelvin(100. * 5 / 9));
    static_assert(not(Rankine(100.) <= Kelvin(99. * 5 / 9)));
    static_assert(Fahrenheit(90.) <= Rankine(100 + 459.67));
  }
  TEST_CASE("Operator<") {
    static_assert(Rankine(100.) < Kelvin(101. * 5 / 9));
    static_assert(not(Rankine(100.) < Kelvin(100. * 5 / 9)));
    static_assert(Fahrenheit(90.).data < Rankine(100 + 459.67).data);
  }
  TEST_CASE("Operator>=") {
    static_assert(Rankine(100.) >= Kelvin(100. * 5 / 9));
    static_assert(Rankine(101.) >= Kelvin(100. * 5 / 9));
    static_assert(not(Rankine(99.) >= Kelvin(100. * 5 / 9)));
    static_assert(Fahrenheit(101.) >= Rankine(100 + 459.67));
  }
  TEST_CASE("Operator>") {
    static_assert(not(Rankine(100.) > Kelvin(100. * 5 / 9)));
    static_assert(Rankine(101.) > Kelvin(100. * 5 / 9));
    static_assert(Fahrenheit(101.) > Rankine(100 + 459.67));
  }
}

// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test