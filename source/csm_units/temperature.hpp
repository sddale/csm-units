// READY TO BE DELETED - PENDING SETH APROOVAL

// #pragma once

// namespace csm_units {

// class DimTemperature {};

// class CelsiusConverter {
//  public:
//   [[nodiscard]] constexpr static auto ToBase(double value) noexcept -> double
//   {
//     return value + 273.15;
//   }

//   [[nodiscard]] constexpr static auto FromBase(double dataKelvin) noexcept
//       -> double {
//     return dataKelvin - 273.15;
//   }
// };

// class FahrenheitConverter {
//  public:
//   [[nodiscard]] constexpr static auto ToBase(double value) noexcept -> double
//   {
//     return (value - 32) / 1.8 + 273.15;
//   }

//   [[nodiscard]] constexpr static auto FromBase(double dataKelvin) noexcept
//       -> double {
//     return (dataKelvin - 273.15) * 1.8 + 32;
//   }
// };

// }  // namespace csm_units