#pragma once

#include <csm_units/concepts.hpp>

#include <tuple>

#include "pressure.hpp"
#include "temperature.hpp"
#include "exponents.hpp"

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

  friend constexpr auto operator|(auto lhs, double rhs) {
    return lhs[0](rhs, lhs[1]);
  }

  [[nodiscard]] constexpr static auto ToBase(double data, ExpType auto exponents) noexcept {
    return (std::make_tuple(LC::ToBase, decltype(exponents)::L) | std::make_tuple(MC::ToBase, decltype(exponents)::MC) | std::make_tuple(TC::ToBase, decltype(exponents)::T) | data);
  }

  [[nodiscard]] constexpr static auto FromBase(double data, ExpType auto exponents) noexcept {
    return (std::make_tuple(LC::FromBase, decltype(exponents)::L) | std::make_tuple(MC::FromBase, decltype(exponents)::MC) | std::make_tuple(TC::FromBase, decltype(exponents)::T) | data);
  }
};

}  // namespace csm_units