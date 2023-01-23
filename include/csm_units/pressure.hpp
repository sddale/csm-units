#pragma once

namespace csm_units {

template <class Converter>
class Pressure : public Converter {
 public:
  constexpr explicit Pressure(double pressure) noexcept
      : data(Converter::ConvertValueTo(pressure)) {}

  auto getData() -> double { return Converter::ConvertValueFrom(data); }
  void setData(double value) { data = Converter::ConvertValueTo(value); }

  auto getDataInPascals() -> double { return data; }

  // Should we make all data members private?
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

class ATMConverter {
 public:
  // 1 atm = 101,325 Pa
  constexpr static auto ConvertValueTo(double atmData) -> double {
    return (atmData * 101325);
  }

  constexpr static auto ConvertValueFrom(double paData) -> double {
    return (paData / 101325);
  }
};

class PSIConverter {
 public:
  // 1 psi = 6894.76 Pa
  constexpr static auto ConvertValueTo(double psiData) -> double {
    return (psiData * 6894.76);
  }

  constexpr static auto ConvertValueFrom(double paData) -> double {
    return (paData / 6894.76);
  }
};

class PSIGConverter {
 public:
  // 1 psig = 6894.76 Pa
  constexpr static auto ConvertValueTo(double psigData) -> double {
    return (psigData * 6894.76);
  }

  constexpr static auto ConvertValueFrom(double paData) -> double {
    return (paData / 6894.76);
  }
};

using Pascals = Pressure<PascalsConverter>;
using Bar = Pressure<BarConverter>;
using ATM = Pressure<ATMConverter>;
using PSI = Pressure<PSIConverter>;
using PSIG = Pressure<PSIGConverter>;

}  // namespace csm_units
