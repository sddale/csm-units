#pragma once

namespace csm_units {

class NoConverter {
 public:
  // do nothing in either of the below because we do not want to convert
  [[nodiscard]] constexpr static auto ToBase(double data) noexcept -> double {
    return data;
  }
  [[nodiscard]] constexpr static auto FromBase(double data) noexcept -> double {
    return data;
  }
};

}  // namespace csm_units