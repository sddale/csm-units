#include <doctest/doctest.h>

#include <csm_units/csm_units.hpp>
#include <string>

namespace csm_units::test {

TEST_CASE("CSMUnits") {
  CSMUnits csm_units("Tests");

  CHECK(csm_units.greet(LanguageCode::EN) == "Hello, Tests!");
  CHECK(csm_units.greet(LanguageCode::DE) == "Hallo Tests!");
  CHECK(csm_units.greet(LanguageCode::ES) == "¡Hola Tests!");
  CHECK(csm_units.greet(LanguageCode::FR) == "Bonjour Tests!");
}

}  // namespace csm_units::test