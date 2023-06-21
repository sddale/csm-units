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

  const Bar P = n * R * T / V;
  return P;
};

constexpr auto UseIG = []() {
  const Mole n = Mole(2);
  const Celsius T = Celsius(100.0);
  const auto V = 10.1_m3;

  const auto pres = IdealGas(n, V, T);

  CHECK_DBL_EQ(pres.data, 0.006143646982);
};

TEST_SUITE("README Demonstration") {
  TEST_CASE("Example") { UseIG(); }
}

// NOLINTEND(readability-identifier-length)
// NOLINTEND(modernize-use-trailing-return-type)