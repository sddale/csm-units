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

using SquareRankine =
    Definition<Dimension<0, 0, 0, 0, 2, 0, 0>, std::ratio<1>, std::ratio<1>,
               std::ratio<1>, std::ratio<1>, std::ratio<9, 5>>;

using Kelvin = Definition<Dimension<0, 0, 0, 0, 1, 0, 0>>;

}  // namespace definition

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Unit arithmetic") {
  constexpr auto R =  // NOLINT(readability-identifier-length)
      definition::Rankine();

  using Rankine = Unit<decltype(R), double>;
  using Kelvin = Unit<definition::Kelvin, double>;
  using Celsius = Unit<definition::Kelvin, double, std::ratio<5463, 20>>;
  using Fahrenheit = Unit<decltype(R), double, std::ratio<45967, 180>>;
  TEST_CASE("Unary operator-") {
    static_assert(-Rankine(100.) == -Kelvin(100. * 5 / 9));
    static_assert(-Rankine(100.) == Kelvin(-100. * 5 / 9));
    CHECK_UNIT_EQ(-Fahrenheit(100.), -Rankine(100 + 459.67));
  }
  TEST_CASE("Subtraction") {
    SUBCASE("Operator-=") {
      {
        auto result = Kelvin(100.);
        result -= Kelvin(99.);
        CHECK_DBL_EQ(result.Get(), Kelvin(1.).Get());
      }
      {
        auto result = Rankine(100.);
        result -= Rankine(99.);
        CHECK_DBL_EQ(result.data, 1. * 5 / 9);
        CHECK_DBL_EQ(result.Get(), Kelvin(1.).Get());
      }
      {
        auto result = Celsius(5) -= Celsius(3);
        CHECK_DBL_EQ(result.data, 2.);
        CHECK_DBL_EQ(result.Get(), Celsius(2 - 273.15).Get());
      }

      {
        auto result = Fahrenheit(5) -= Fahrenheit(3);
        CHECK_DBL_EQ(result.data, 2. * 5 / 9);
        CHECK_DBL_EQ(result.Get(), Fahrenheit(2 - 459.67).Get());
      }
    }
    SUBCASE("Binary operator-") {
      {
        const auto result = Kelvin(100.) - Kelvin(99);
        CHECK_DBL_EQ(result.Get(), Kelvin(1.).Get());
      }
      {
        const auto result = Rankine(100.) - Rankine(99);
        CHECK_DBL_EQ(result.data, 1. * 5 / 9);
        CHECK_DBL_EQ(result.Get(), Kelvin(1.).Get());
      }
      {
        const auto result = Celsius(5) - Celsius(3);
        CHECK_DBL_EQ(result.data, 2.);
        CHECK_DBL_EQ(result.SI(), 2.);
        CHECK_DBL_EQ(result.Get(), Celsius(2 - 273.15).Get());
      }
      {
        const auto result = Fahrenheit(5) - Fahrenheit(3);
        CHECK_DBL_EQ(result.data, 2. * 5 / 9);
        CHECK_DBL_EQ(result.Get(), Fahrenheit(2 - 459.67).Get());
      }
      {
        const auto result = Celsius(5) - Fahrenheit(37.4);
        CHECK_DBL_EQ(result.data, 2.);
        CHECK_DBL_EQ(result.Get(), Celsius(2 - 273.15).Get());
      }
    }
  }
  TEST_CASE("Addition") {
    SUBCASE("Operator+=") {
      {
        auto val = Kelvin(100.);
        val += Kelvin(99.);
        CHECK_DBL_EQ(val.Get(), Kelvin(199.).Get());
      }
      {
        auto val = Rankine(100.);
        val += Rankine(99.);
        CHECK_DBL_EQ(val.data, 199. * 5 / 9);
        CHECK_DBL_EQ(val.Get(), Kelvin(199.).Get());
      }
      {
        const auto result = Celsius(5) += Celsius(3);
        CHECK_DBL_EQ(result.data, 8 + 2 * 273.15);
        CHECK_DBL_EQ(result.SI(), 8 + 2 * 273.15);
        CHECK_DBL_EQ(result.Get(), Celsius(8 + 273.15).Get());
      }
      {
        const auto result = Fahrenheit(5) += Fahrenheit(3);
        CHECK_DBL_EQ(result.data, (8. + 2 * 459.67) * 5 / 9);
        CHECK_DBL_EQ(result.Get(), Fahrenheit(8 + 459.67).Get());
      }
      {
        const auto result = Celsius(5) += Fahrenheit(37.4);
        CHECK_DBL_EQ(result.data, 8 + 2 * 273.15);
        CHECK_DBL_EQ(result.Get(), Celsius(8 + 273.15).Get());
      }
    }
    SUBCASE("Binary operator+") {
      {
        const auto result = Kelvin(100.) + Kelvin(99);
        CHECK_DBL_EQ(result.Get(), Kelvin(199.).Get());
      }
      {
        const auto result = Rankine(100.) + Rankine(99);
        CHECK_DBL_EQ(result.data, 199. * 5 / 9);
        CHECK_DBL_EQ(result.Get(), Kelvin(199.).Get());
      }
      {
        const auto result = Celsius(5) + Celsius(3);
        CHECK_DBL_EQ(result.data, 8 + 2 * 273.15);
        CHECK_DBL_EQ(result.Get(), Celsius(8 + 273.15).Get());
      }
      {
        const auto result = Fahrenheit(5) + Fahrenheit(3);
        CHECK_DBL_EQ(result.data, (8. + 2 * 459.67) * 5 / 9);
        CHECK_DBL_EQ(result.Get(), Fahrenheit(8 + 459.67).Get());
      }
      {
        const auto result = Celsius(5) + Fahrenheit(37.4);
        CHECK_DBL_EQ(result.data, 8 + 2 * 273.15);
        CHECK_DBL_EQ(Celsius(Fahrenheit(5)).Get(), -15);
        CHECK_DBL_EQ(Fahrenheit(Celsius(5)).Get(), 41);
        CHECK_DBL_EQ(Celsius(Kelvin(300)).Get(), 300 - 273.15);
        CHECK_DBL_EQ(Kelvin(Celsius(300)).Get(), 300 + 273.15);
        CHECK_DBL_EQ(Fahrenheit(Rankine(1000)).Get(), 540.33);
        CHECK_DBL_EQ(result.Get(), Celsius(8 + 273.15).Get());
      }
    }
  }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test