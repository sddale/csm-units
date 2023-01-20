#pragma once

namespace csm_units {

class Pressure {
 public:
  constexpr explicit Pressure(double pressure) noexcept : data(pressure) {}
  double data;  // Pa
};

}  // namespace csm_units
