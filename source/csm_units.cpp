#include <fmt/format.h>

#include <csm_units/csm_units.hpp>

namespace csm_units {

CSMUnits::CSMUnits(std::string _name) : name(std::move(_name)) {}

auto CSMUnits::greet(LanguageCode lang) const -> std::string {
  switch (lang) {
    default:
    case LanguageCode::EN:
      return fmt::format("Hello, {}!", name);
    case LanguageCode::DE:
      return fmt::format("Hallo {}!", name);
    case LanguageCode::ES:
      return fmt::format("¡Hola {}!", name);
    case LanguageCode::FR:
      return fmt::format("Bonjour {}!", name);
  }
}

}  // namespace csm_units
