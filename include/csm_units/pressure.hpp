#pragma once

namespace csm_units {

template <class Converter>
class Pressure : public Converter {
 public:
  constexpr explicit Pressure(double pressure) noexcept
      : data(Converter::ConvertValueTo(pressure)) {}

  // Get value in original unit (i.e. Bar if BarConverter)
  constexpr auto Value() const noexcept -> double {
    return Converter::ConvertValueFrom(data);
  }

  // Get raw stored value (i.e. in Pascals)
  [[nodiscard]] constexpr auto Data() const noexcept -> double { return data; }

  constexpr void Set(double value) noexcept {
    data = Converter::ConvertValueTo(value);
  }

  constexpr auto getDataInPascals() const noexcept -> double { return data; }

 private:
  double data;  // Pa
};

class PascalsConverter {
 public:
  // do nothing in either of the below because we want it in pascals
  constexpr static auto ConvertValueTo(double paData) -> double {
    return paData;
  }
  constexpr static auto ConvertValueFrom(double paData) -> double {
    return paData;
  }
};

class BarConverter {
 public:
  // 1 bar = 100,000 pascals
  constexpr static auto ConvertValueTo(double barData) -> double {
    return (barData * 100000);
  }

  constexpr static auto ConvertValueFrom(double paData) -> double {
    return (paData / 100000);
  }
};

class AtmConverter {
 public:
  // 1 atm = 101,325 Pa
  constexpr static auto ConvertValueTo(double atmData) -> double {
    return (atmData * 101325);
  }

  constexpr static auto ConvertValueFrom(double paData) -> double {
    return (paData / 101325);
  }
};

class PsiConverter {
 public:
  // 1 psi = 6894.76 Pa
  constexpr static auto ConvertValueTo(double psiData) -> double {
    return (psiData * 6894.7572931783);
  }

  constexpr static auto ConvertValueFrom(double paData) -> double {
    return (paData / 6894.7572931783);
  }
};

using Pascals = Pressure<PascalsConverter>;
using Bar = Pressure<BarConverter>;
using Atm = Pressure<AtmConverter>;
using Psi = Pressure<PsiConverter>;

}  // namespace csm_units
