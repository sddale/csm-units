#pragma once

class Pressure {
 public:
  constexpr explicit Pressure(double pressure) noexcept : data(pressure) {}
  double data;  // Pa
};
