#pragma once

namespace csm_units {

class Temperature {
 public:
  constexpr explicit Temperature(double temperature) noexcept
      : data(temperature) {}

  double data;
};

}  // namespace csm_units