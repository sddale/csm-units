#pragma once

#include <csm_units/concepts.hpp>
#include <cstdint>
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
    return data + pow * 0;
  }
  [[nodiscard]] constexpr static auto FromBase(double data, int pow) noexcept
      -> double {
    return data + pow * 0;
  }
};

constexpr auto operator|(double lhs, auto rhs) {
  return std::get<0>(rhs)(lhs, std::get<1>(rhs));
}

template <ConverterType LC = NoConverter, ConverterType MC = NoConverter,
          ConverterType TC = NoConverter, ConverterType CC = NoConverter,
          ConverterType TPC = NoConverter, ConverterType AC = NoConverter,
          ConverterType LMC = NoConverter>
struct Converters {
  // Come back to this because a bit confused about how to get converters to
  // work the best

  [[nodiscard]] constexpr static auto ToBase(double data,
                                             ExpType auto exponents) noexcept {
    return data | std::make_tuple(LMC::ToBase, decltype(exponents)::LM::num) |
           std::make_tuple(AC::ToBase, decltype(exponents)::A::num) |
           std::make_tuple(TPC::ToBase, decltype(exponents)::TP::num) |
           std::make_tuple(CC::ToBase, decltype(exponents)::C::num) |
           std::make_tuple(TC::ToBase, decltype(exponents)::T::num) |
           std::make_tuple(MC::ToBase, decltype(exponents)::M::num) |
           std::make_tuple(LC::ToBase, decltype(exponents)::L::num);
  }

  [[nodiscard]] constexpr static auto FromBase(
      double data, ExpType auto exponents) noexcept {
    return data | std::make_tuple(LMC::FromBase, decltype(exponents)::LM::num) |
           std::make_tuple(AC::FromBase, decltype(exponents)::A::num) |
           std::make_tuple(TPC::FromBase, decltype(exponents)::TP::num) |
           std::make_tuple(CC::FromBase, decltype(exponents)::C::num) |
           std::make_tuple(TC::FromBase, decltype(exponents)::T::num) |
           std::make_tuple(MC::FromBase, decltype(exponents)::M::num) |
           std::make_tuple(LC::FromBase, decltype(exponents)::L::num);
  }
};

}  // namespace csm_units