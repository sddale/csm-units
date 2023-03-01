#pragma once

#include "base.hpp"

namespace csm_units {

// class DimPressure {};  // should probably get rid of this

/*
// Converters to define relationship between various pressure units
class PascalsConverter {
 public:
  // do nothing in either of the below because we want it in pascals
  [[nodiscard]] constexpr static auto ToBase(double paData) noexcept -> double {
    return paData;
  }
  [[nodiscard]] constexpr static auto FromBase(double paData) noexcept
      -> double {
    return paData;
  }
};
*/  // *** All of this shouldn't be needed anymore, but want to talk to Seth
    // before deleting ***

class BarConverter {
 public:
  // 1 bar = 100,000 pascals
  [[nodiscard]] constexpr static auto ToBase(double barData) noexcept
      -> double {
    return (barData * 100000);
  }

  [[nodiscard]] constexpr static auto FromBase(double paData) noexcept
      -> double {
    return (paData / 100000);
  }
};

class AtmConverter {
 public:
  // 1 atm = 101,325 Pa
  [[nodiscard]] constexpr static auto ToBase(double atmData) noexcept
      -> double {
    return (atmData * 101325);
  }

  [[nodiscard]] constexpr static auto FromBase(double paData) noexcept
      -> double {
    return (paData / 101325);
  }
};

class PsiConverter {
 public:
  // 1 psi = 6894.76 Pa
  [[nodiscard]] constexpr static auto ToBase(double psiData) noexcept
      -> double {
    return (psiData * 6894.7572931783);
  }

  [[nodiscard]] constexpr static auto FromBase(double paData) noexcept
      -> double {
    return (paData / 6894.7572931783);
  }
};

}  // namespace csm_units
