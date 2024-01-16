#include <doctest/doctest.h>

#include <csm_units/concepts.hpp>
#include <csm_units/temperature.hpp>
#include <source/csm_units/definition.hpp>
#include <source/csm_units/dimension.hpp>
#include <source/csm_units/unit.hpp>

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Size") {
  using namespace literals;
  TEST_CASE("Default") {
    static_assert(sizeof(CSMUNITS_VALUE_TYPE) == sizeof(Kelvin));
  }
  TEST_CASE("Template initialization") {
    static_assert(sizeof(double) == sizeof(Unit<K, double>));
    static_assert(sizeof(float) == sizeof(Unit<K, float>));
  }
  TEST_CASE("Operator*") {
    static_assert(sizeof(double) ==
                  sizeof(decltype(Unit<K, double>() * Unit<K, float>())));
    static_assert(sizeof(double) ==
                  sizeof(decltype(Unit<K, float>() * Unit<K, double>())));
  }
  TEST_CASE("Operator/") {
    static_assert(sizeof(double) ==
                  sizeof(decltype(Unit<K, double>() / Unit<K, float>())));
    static_assert(sizeof(double) ==
                  sizeof(decltype(Unit<K, float>() / Unit<K, double>())));
  }
  TEST_CASE("Operator-") {
    static_assert(sizeof(double) ==
                  sizeof(decltype(Unit<K, double>() - Unit<K, float>())));
    static_assert(sizeof(float) ==
                  sizeof(decltype(Unit<K, float>() - Unit<K, double>())));
  }
  TEST_CASE("Operator+") {
    static_assert(sizeof(double) ==
                  sizeof(decltype(Unit<K, double>() + Unit<K, float>())));
    static_assert(sizeof(float) ==
                  sizeof(decltype(Unit<K, float>() + Unit<K, double>())));
  }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test