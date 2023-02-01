#pragma once

#include <cmath>
#include <compare>
#include <cstdlib>

namespace csm_units {

template <class Converter>
class Pressure {
 public:
  constexpr explicit Pressure(double pressure) noexcept : data(pressure) {}

  // copy constructor for pressures with the same unit
  constexpr explicit Pressure(const Pressure& to_copy) noexcept
      : data(to_copy.data) {}

  // copy constructor for pressures with different unit
  template <class OtherConverter>
  constexpr explicit Pressure(const Pressure<OtherConverter>& to_move) noexcept
      : data(converter.ConvertValueFrom(
            OtherConverter::ConvertValue(to_move.data))) {}

  // move constructor
  constexpr Pressure(Pressure&& to_move) noexcept : data(to_move.Data()) {}

  constexpr auto operator<=>(const Pressure& rhs) const noexcept {
    return data <=> rhs.data;
  }

  constexpr auto operator==(const Pressure& rhs) const noexcept -> bool {
    return data == rhs.data;
  }

  template <class OtherConverter>
  constexpr auto operator<=>(
      const Pressure<OtherConverter>& rhs) const noexcept {
    return converter.ConvertValue(data) <=>
           OtherConverter::ConvertValue(rhs.data);
  }

  template <class OtherConverter>
  constexpr auto operator==(const Pressure<OtherConverter>& rhs) const noexcept
      -> bool {
    return converter.ConvertValue(data) ==
           OtherConverter::ConvertValue(rhs.data);
  }

  constexpr auto operator<=>(double rhs) const noexcept { return data <=> rhs; }

  constexpr auto operator==(double rhs) const noexcept -> bool {
    return data == rhs;
  }

  double data;

 private:
  [[no_unique_address]] Converter
      converter;  // Performance compared to references to static i.e.
                  // converter.Convert vs. Converter::Convert ?
};

class PascalsConverter {
 public:
  // do nothing in either of the below because we want it in pascals
  [[nodiscard]] constexpr static auto ConvertValue(double paData) noexcept
      -> double {
    return paData;
  }
  [[nodiscard]] constexpr static auto ConvertValueFrom(double paData) noexcept
      -> double {
    return paData;
  }
};

class BarConverter {
 public:
  // 1 bar = 100,000 pascals
  [[nodiscard]] constexpr static auto ConvertValue(double barData) noexcept
      -> double {
    return (barData * 100000);
  }

  [[nodiscard]] constexpr static auto ConvertValueFrom(double paData) noexcept
      -> double {
    return (paData / 100000);
  }
};

class AtmConverter {
 public:
  // 1 atm = 101,325 Pa
  [[nodiscard]] constexpr static auto ConvertValue(double atmData) noexcept
      -> double {
    return (atmData * 101325);
  }

  [[nodiscard]] constexpr static auto ConvertValueFrom(double paData) noexcept
      -> double {
    return (paData / 101325);
  }
};

class PsiConverter {
 public:
  // 1 psi = 6894.76 Pa
  [[nodiscard]] constexpr static auto ConvertValue(double psiData) noexcept
      -> double {
    return (psiData * 6894.7572931783);
  }

  [[nodiscard]] constexpr static auto ConvertValueFrom(double paData) noexcept
      -> double {
    return (paData / 6894.7572931783);
  }
};

using Pascals = Pressure<PascalsConverter>;
using Bar = Pressure<BarConverter>;
using Atm = Pressure<AtmConverter>;
using Psi = Pressure<PsiConverter>;

}  // namespace csm_units
