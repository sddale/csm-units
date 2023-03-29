#pragma once

#include "unit.hpp"

namespace csm_units {

template <UnitType SI, RatioType Ratio>
class Customary {
 public:
  // constexpr explicit Customary(double value = 0) noexcept : data(value){};

  // // copy constructor
  // constexpr Customary(const Customary& other) noexcept = default;

  // // move constructor
  // constexpr Customary(Customary&& other) noexcept = default;

  // double data;  // Come back to this for arbitrary data type
};

}  // namespace csm_units