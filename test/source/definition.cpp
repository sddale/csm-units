#include <doctest/doctest.h>

#include <csm_units/concepts.hpp>
#include <gcem.hpp>
#include <source/csm_units/definition.hpp>
#include <source/csm_units/dimension.hpp>
#include <source/csm_units/unit.hpp>

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

constexpr auto R =  // NOLINT(readability-identifier-length)
    definition::Rankine();

using Rankine = Unit<decltype(R), double>;

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

TEST_SUITE("Definition") {
  TEST_CASE("Construction via operator*") {
    static_assert(
        std::is_same_v<Unit<definition::Rankine, double>, decltype(1.0 * R)>);
    static_assert(std::is_same_v<Unit<definition::SquareRankine, double>,
                                 decltype(1.0 * R * R)>);
    static_assert(std::is_same_v<Unit<definition::SquareRankine, double>,
                                 decltype(Rankine(1.0) * R)>);
  }
}

// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test