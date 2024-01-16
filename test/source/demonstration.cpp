#include <doctest/doctest.h>

#include <csm_units/concepts.hpp>
#include <csm_units/units.hpp>

#include "common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type,readability-identifier-length,misc-use-anonymous-namespace)

using namespace csm_units;
using namespace csm_units::literals;

constexpr auto IdealGas(Kilomole n, Liter volume, Fahrenheit temperature) {
  const auto R = 8.3145 * m3 * Pa / (K * mol);

  static_assert(std::convertible_to<decltype(R), decltype(1_J / (mol * K))>);
  static_assert(not std::convertible_to<decltype(R), decltype(1_J)>);

  const Bar P = n * R * temperature / volume;  // implicit conversion
  return P;
};

constexpr auto UseIG() {
  return IdealGas(2_mol, 10.1_m3,
                  100.0_degC);  // implicit parameter conversions
};

TEST_SUITE("README Demonstration") {
  TEST_CASE("Example") { CHECK_UNIT_EQ(UseIG(), 0.006144_Pa); }
}
// NOLINTEND(modernize-use-trailing-return-type,readability-identifier-length,misc-use-anonymous-namespace)

}  // namespace csm_units::test