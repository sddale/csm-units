#pragma once

#include <csm_units/concepts.hpp>

#include "pressure.hpp"
#include "temperature.hpp"

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

template <ConverterType LC = NoConverter, ConverterType MC = NoConverter,
          ConverterType TC = NoConverter>
struct Converters {
  // Come back to this because a bit confused about how to get converters to
  // work the best

  [[nodiscard]] constexpr static auto LengthConvertTo(double data) noexcept
      -> double {
    return LC::ToBase(data);
  }

  [[nodiscard]] constexpr static auto MassConvertTo(double data) noexcept
      -> double {
    return MC::ToBase(data);
  }

  [[nodiscard]] constexpr static auto TimeConvertTo(double data) noexcept
      -> double {
    return LC::ToBase(data);
  }

  [[nodiscard]] constexpr static auto LengthConvertFrom(double data) noexcept
      -> double {
    return LC::FromBase(data);
  }

  [[nodiscard]] constexpr static auto MassConvertFrom(double data) noexcept
      -> double {
    return LC::FromBase(data);
  }

  [[nodiscard]] constexpr static auto TimeConvertFrom(double data) noexcept
      -> double {
    return LC::FromBase(data);
  }
};

}  // namespace csm_units