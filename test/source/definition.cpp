#include <doctest/doctest.h>

#include <csm_units/concepts.hpp>
#include <source/csm_units/definition.hpp>
#include <source/csm_units/dimension.hpp>
#include <source/csm_units/unit.hpp>

#ifndef CSMUNITS_VALUE_TYPE
#define CSMUNITS_VALUE_TYPE double
#endif

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

TEST_SUITE("Definition") {
  using namespace csm_units::literals;
  using length_def = Definition<Dimension<One>>;
  using inv_def = decltype(One() / length_def());
  using area_def = decltype(length_def() * length_def());
  using dimensionless = decltype(length_def() / length_def());
  TEST_CASE("Construction via operator*") {
    static_assert(std::is_same_v<length_def::DimenType, Dimension<One>>);
    static_assert(std::is_same_v<area_def::DimenType, Dimension<Two>>);
    static_assert(std::is_same_v<dimensionless, CSMUNITS_VALUE_TYPE>);
    static_assert(
        std::is_same_v<decltype(area_def() / length_def()), length_def>);
    static_assert(std::is_same_v<decltype(length_def() / area_def()), inv_def>);
  }
}

// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test