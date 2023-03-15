#pragma once

#include <csm_units/concepts.hpp>
#include <tuple>

#include "exponents.hpp"
#include "pressure.hpp"
#include "temperature.hpp"

namespace csm_units {

class NoConverter {
 public:
  // do nothing in either of the below because we do not want to convert
  [[nodiscard]] constexpr static auto ToBase(double data, int pow) noexcept
      -> double {
    return data;
  }
  [[nodiscard]] constexpr static auto FromBase(double data, int pow) noexcept
      -> double {
    return data;
  }
};

constexpr auto operator|(
    double lhs, std::tuple<double (*)(double, int) noexcept, long> rhs) {
  return std::get<0>(rhs)(lhs, static_cast<int>(std::get<1>(rhs)));
}

template <ConverterType LC = NoConverter, ConverterType MC = NoConverter,
          ConverterType TC = NoConverter>
struct Converters {
  // Come back to this because a bit confused about how to get converters to
  // work the best

  [[nodiscard]] constexpr static auto ToBase(double data,
                                             ExpType auto exponents) noexcept {
    return data | std::make_tuple(TC::ToBase, decltype(exponents)::T::num) |
           std::make_tuple(MC::ToBase, decltype(exponents)::M::num) |
           std::make_tuple(LC::ToBase, decltype(exponents)::L::num);
  }

  [[nodiscard]] constexpr static auto FromBase(
      double data, ExpType auto exponents) noexcept {
    return data | std::make_tuple(TC::FromBase, decltype(exponents)::T::num) |
           std::make_tuple(MC::FromBase, decltype(exponents)::M::num) |
           std::make_tuple(LC::FromBase, decltype(exponents)::L::num);
  }
};

}  // namespace csm_units