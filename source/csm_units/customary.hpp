#pragma once

#include "unit.hpp"

namespace csm_units {

template <UnitType SI, RatioType Power, class Converter, Arithmetic Data>
class Customary {
 public:
  constexpr explicit Customary(Data value = 0) noexcept {
    represented.data = value;
  }

  // copy constructor
  constexpr Customary(const Customary& other) noexcept = default;

  // move constructor
  constexpr Customary(Customary&& other) noexcept = default;

  SI represented;

  constexpr static auto FromBase(Data data) {
    return Converter::FromBase(data, Power::num);
  }

  constexpr static auto ToBase(Data data) {
    return Converter::ToBase(data, Power::den);
  }
};

}  // namespace csm_units