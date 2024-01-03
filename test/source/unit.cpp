#include <doctest/doctest.h>

#include <csm_units/concepts.hpp>
#include <source/csm_units/definition.hpp>
#include <source/csm_units/dimension.hpp>
#include <source/csm_units/unit.hpp>
// #include <csm_units/units.hpp>
#include <gcem.hpp>

#include "common.hpp"

namespace csm_units::test {

namespace definition {

using Rankine =
    Definition<Dimension<0, 0, 0, 0, 1, 0, 0>, std::ratio<1>, std::ratio<1>,
               std::ratio<1>, std::ratio<1>, std::ratio<9, 5>>;

using SquareRankine =
    Definition<Dimension<0, 0, 0, 0, 2, 0, 0>, std::ratio<1>, std::ratio<1>,
               std::ratio<1>, std::ratio<1>, std::ratio<9, 5>>;

using Kelvin = Definition<Dimension<0, 0, 0, 0, 1, 0, 0>>;

}  // namespace definition

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Unit") {
  constexpr auto R =  // NOLINT(readability-identifier-length)
      definition::Rankine();

  using Rankine = Unit<decltype(R), double>;
  using Kelvin = Unit<definition::Kelvin, double>;
  using Celsius = Unit<definition::Kelvin, double, std::ratio<5463, 20>>;
  using Fahrenheit = Unit<decltype(R), double, std::ratio<45967, 180>>;

  TEST_CASE("Get() and .data") {
    static_assert(Rankine(100.).Get() == 100.);
    static_assert(Rankine(100.).data == Kelvin(100. * 5 / 9).data);
    static_assert(Rankine(100.).data == 100. * 5 / 9);
    static_assert(Kelvin(100.).Get() == Kelvin(100.).data);
    CHECK_DBL_EQ(Fahrenheit(100.).Get(), 100);
    CHECK_DBL_EQ(Fahrenheit(100.).data, Celsius(37.7778).data);
    CHECK_DBL_EQ(Fahrenheit(100.).data, Rankine(100 + 459.67).data);
    CHECK_EQ(Fahrenheit(100.).data,
             doctest::Approx(Kelvin((100 - 32) * 5. / 9 + 273.15).Get()));
  }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test