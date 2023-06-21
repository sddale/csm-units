#include <doctest/doctest.h>

#include <csm_units/units.hpp>

#include "source/csm_units/named_units/pressure/pascal.hpp"
#include "source/csm_units/named_units/volume/cubic_meter.hpp"

using csm_units::Bar;
using csm_units::Celsius;
using csm_units::Fahrenheit;
using csm_units::Kilomole;
using csm_units::Liter;
using csm_units::Mole;

using csm_units::literals::K;
using csm_units::literals::m3;
using csm_units::literals::mol;
using csm_units::literals::Pa;

using namespace csm_units::literals;

// NOLINTBEGIN(modernize-use-trailing-return-type)
// NOLINTBEGIN(readability-identifier-length)

constexpr auto CHECK_TYPE = [](auto input, auto ref) {
  CHECK(std::is_same_v<std::remove_const_t<decltype(input)>,
                       std::remove_const_t<decltype(ref)>>);
};

constexpr auto CHECK_DBL_EQ = [](auto lhs, auto rhs) {
  CHECK_EQ(lhs, doctest::Approx(rhs));
};

constexpr auto IdealGas = [](Kilomole n, Liter V, Fahrenheit T) -> Bar {
  const auto R = 8.31446261815324 <<= m3 * Pa / K / mol;

  CHECK_TYPE(
      R,
      csm_units::UnitBase<csm_units::Exponents<2, 1, -2, 0, -1, -1, 0>, double>(
          0.0));

  // Using literals we can build what units the ideal gas constant R is
  // using and assign that to the double.

  // Conversion between units automatically occurs to ensure that arithmetic
  // is following the rules set in place by the units. This can be seen
  // below where R is Cubic Meter, Pascals, Kelvin, and Mole. While the
  // arguments for the moles of the gas (n), volume, and temperature are in
  // Kilomole, Liter, and Fahrenheit respectively. As well the answer is
  // looking for Bar. All of the conversion happens behind the scene to
  // ensure the answer is correct to Bar.

  const Bar P = n * R * T / V;
  return P;
};

constexpr auto UseIG = []() {
  const Mole n = Mole(2);
  const Celsius T = Celsius(100.0);
  const auto V = 10.1_m3;  // string literal operators
  // const auto pres = IdealGas(n,T,V); // Does not
  // compile
  const auto pres = IdealGas(n, V, T);
  // The same auto converting happens when units are
  // passed that are the same dimension, but different
  // unit.

  CHECK_DBL_EQ(pres.data, 0.006143646982);
};

TEST_SUITE("README Demonstration") {
  TEST_CASE("Example") { UseIG(); }
}

// NOLINTEND(readability-identifier-length)
// NOLINTEND(modernize-use-trailing-return-type)