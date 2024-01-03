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

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

TEST_SUITE("Definition") {
  using namespace csm_units::literals;
  using SquareRankine =
      Definition<DimensionAdd<Temperature, Temperature>, std::ratio<1>,
                 std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<9, 5>>;
  TEST_CASE("Construction via operator*") {
    static_assert(std::is_same_v<Unit<definition::Rankine, double>,
                                 decltype(1.0 * degR)>);
    static_assert(std::is_same_v<Unit<SquareRankine, double>,
                                 decltype(1.0 * degR * degR)>);
    static_assert(std::is_same_v<Unit<SquareRankine, double>,
                                 decltype(Rankine(1.0) * degR)>);
  }
}

// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test