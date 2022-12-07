#include <csm_units/csm_units.hpp>
#include <iostream>
#include <string>
#include <unordered_map>

auto main(int /*argc*/, char** /*argv*/) -> int {
  const std::unordered_map<std::string, csm_units::LanguageCode> languages{
      {"en", csm_units::LanguageCode::EN},
      {"de", csm_units::LanguageCode::DE},
      {"es", csm_units::LanguageCode::ES},
      {"fr", csm_units::LanguageCode::FR},
  };

  std::string language;
  std::string name;

  auto langIt = languages.find(language);
  if (langIt == languages.end()) {
    std::cerr << "unknown language code: " << language << std::endl;
    return 1;
  }

  csm_units::CSMUnits csm_units(name);
  std::cout << csm_units.greet(langIt->second) << std::endl;

  return 0;
}
