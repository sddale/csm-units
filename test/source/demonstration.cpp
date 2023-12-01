#include <doctest/doctest.h>

#include <csm_units/units.hpp>

namespace csm_units::test {

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

constexpr auto IdealGas = [](csm_units::Kilomole n, csm_units::Liter Volume,
                             csm_units::Fahrenheit Temp) -> csm_units::Bar {
  const auto R = 8.31446261815324 * m3 * Pa / K / mol;

  CHECK_TYPE(
      R,
      csm_units::UnitBase<csm_units::Exponents<2, 1, -2, 0, -1, -1, 0>, double>(
          0.0));

  const csm_units::Bar P = n * R * Temp / Volume;
  return P;
};

constexpr auto UseIG = []() {
  const auto n = csm_units::Mole(2);
  const auto Temp = csm_units::Celsius(100.0);
  const auto Volume = 10.1_m3;

  const auto pres = IdealGas(n, Volume, Temp);

  CHECK_DBL_EQ(pres.data, 0.006143646982);
};

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("README Demonstration") {
  TEST_CASE("Example") { UseIG(); }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

// NOLINTEND(readability-identifier-length)
// NOLINTEND(modernize-use-trailing-return-type)

}  // namespace csm_units::test