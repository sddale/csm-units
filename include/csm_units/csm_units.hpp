#pragma once

#include <string>

namespace csm_units {

enum class LanguageCode { EN, DE, ES, FR };

class CSMUnits {
  std::string name;

 public:
  CSMUnits(std::string name);
  std::string greet(LanguageCode lang = LanguageCode::EN) const;
};

}  // namespace csm_units
