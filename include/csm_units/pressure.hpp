#pragma once

namespace csm_units {

template <class Converter>
class Pressure : public Converter {
 public:
  constexpr explicit Pressure(double pressure) noexcept
      : data(converter.ConvertValueTo(pressure)) {}

  // Get value in original unit (i.e. Bar if BarConverter)
  [[nodiscard]] constexpr auto Value() const noexcept -> double {
    return converter.ConvertValueFrom(data);
  }

  // Get raw stored value (i.e. in Pascals)
  [[nodiscard]] constexpr auto Data() const noexcept -> double { return data; }

  constexpr void Set(double value) noexcept {
    data = Converter::ConvertValueTo(value);
  }

 private:
  [[no_unique_address]] Converter converter;
  double data;  // Pa
};

class PascalsConverter {
 public:
  // do nothing in either of the below because we want it in pascals
  [[nodiscard]] constexpr static auto ConvertValueTo(double paData) noexcept
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
  [[nodiscard]] constexpr static auto ConvertValueTo(double barData) noexcept
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
  [[nodiscard]] constexpr static auto ConvertValueTo(double atmData) noexcept
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
  [[nodiscard]] constexpr static auto ConvertValueTo(double psiData) noexcept
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
