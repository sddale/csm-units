#include <doctest/doctest.h>

#include <csm_units/concepts.hpp>
#include <gcem.hpp>
#include <source/csm_units/definition.hpp>
#include <source/csm_units/dimension.hpp>
#include <source/csm_units/named_units/thermodynamic_temperature/celsius.hpp>
#include <source/csm_units/named_units/thermodynamic_temperature/fahrenheit.hpp>
#include <source/csm_units/named_units/thermodynamic_temperature/kelvin.hpp>
#include <source/csm_units/named_units/thermodynamic_temperature/rankine.hpp>
#include <source/csm_units/unit.hpp>

#include "common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Comparison") {
  TEST_CASE("Operator==") {
    CHECK_UNIT_EQ(Rankine(100.), Kelvin(100. * 5 / 9));
    CHECK_UNIT_EQ(Fahrenheit(100.), Rankine(100 + 459.67));
    CHECK_DBL_EQ(Fahrenheit(100).data, Celsius(37.7778).data);
  }
  TEST_CASE("Operator!=") {
    static_assert(Rankine(100.) != Kelvin(101. * 5 / 9));
    static_assert(Fahrenheit(90.) != Rankine(100 + 459.67));
    CHECK(Fahrenheit(101).data != doctest::Approx(Celsius(37.7778).data));
  }
  TEST_CASE("Operator<=") {
    CHECK(Rankine(100.).data <= doctest::Approx(Kelvin(100. * 5 / 9).data));
    static_assert(not(Rankine(100.) <= Kelvin(99. * 5 / 9)));
    static_assert(Fahrenheit(90.) <= Rankine(100 + 459.67));
  }
  TEST_CASE("Operator<") {
    CHECK(Rankine(100.).data < doctest::Approx(Kelvin(101. * 5 / 9).data));
    static_assert(not(Rankine(100.) < Kelvin(100. * 5 / 9)));
    static_assert(Fahrenheit(90.).data < Rankine(100 + 459.67).data);
  }
  TEST_CASE("Operator>=") {
    static_assert(Rankine(100.) >= Kelvin(100. * 5 / 9));
    static_assert(Rankine(101.) >= Kelvin(100. * 5 / 9));
    CHECK(not(Rankine(99.).data >= doctest::Approx(Kelvin(100. * 5 / 9).data)));
    CHECK(Fahrenheit(101.).data >= doctest::Approx(Rankine(100 + 459.67).data));
  }
  TEST_CASE("Operator>") {
    CHECK(not(Rankine(100.).data > doctest::Approx(Kelvin(100. * 5 / 9).data)));
    static_assert(Rankine(101.) > Kelvin(100. * 5 / 9));
    CHECK(Fahrenheit(101.).data > doctest::Approx(Rankine(100 + 459.67).data));
  }
}

// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test