#include <doctest/doctest.h>

#include <csm_units/concepts.hpp>
#include <csm_units/temperature.hpp>
#include <gcem.hpp>
#include <source/csm_units/definition.hpp>
#include <source/csm_units/dimension.hpp>
#include <source/csm_units/unit.hpp>

#include "common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Unit") {
  TEST_CASE("Get() and .data") {
    static_assert(Rankine(100.).Get() == 100.);
    CHECK_UNIT_EQ(Rankine(100.), Kelvin(100. * 5 / 9));
    CHECK_UNIT_EQ(Celsius(100.), Kelvin(100 + 273.15));
    CHECK_DBL_EQ(Rankine(100.).data, 100. * 5 / 9);
    static_assert(Kelvin(100.).Get() == Kelvin(100.).data);
    CHECK_DBL_EQ(Fahrenheit(100.).Get(), 100);
    CHECK_DBL_EQ(Fahrenheit(100.).data, Rankine(559.67).data);
    CHECK_DBL_EQ(Fahrenheit(100.).data, Celsius(37.7778).data);
    CHECK_DBL_EQ(Fahrenheit(100.).data, Rankine(100 + 459.67).data);
    CHECK_EQ(Fahrenheit(100.).data,
             doctest::Approx(Kelvin((100 - 32) * 5. / 9 + 273.15).Get()));
  }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test