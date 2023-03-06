#pragma once

#include <compare>
#include <csm_units/concepts.hpp>
#include <ratio>
#include <type_traits>

#include "converter.hpp"

namespace csm_units {

template <class Dimension, ConverterType Converter = NoConverter,
          class Ratio = std::ratio<1, 1>, Arithmetic Data = double>
class Base {
  template <ConverterType T, class R>
  using OtherBase = Base<Dimension, T, R, Data>;

 public:
  constexpr explicit Base(double value) noexcept : data(value) {}

  // copy constructor for units of the same dimensions and converter
  constexpr Base(const Base& other) noexcept = default;

  // copy constructor for units of the same dimension and different converter
  template <class T, class R>
  constexpr Base(const OtherBase<T, R>& other) noexcept
      : data(Converter::FromBase(T::ToBase(other.data))) {}

  template <class T>
  constexpr auto operator=(const Base<Dimension, T, Data>& other) noexcept
      -> Base& {
    if (this == &other) {
      return *this;
    }
    if constexpr (std::is_same_v<Converter, T>) {
      data = other.data;
    } else {
      data = Converter::FromBase(T::ToBase(other.data));
    }
    return *this;
  }

  // Comparison operator overloads
  constexpr auto operator<=>(Arithmetic auto rhs) const noexcept {
    return data <=> rhs;
  }

  template <class T, class R>
  constexpr auto operator<=>(
      const Base<Dimension, T, R, Data>& rhs) const noexcept {
    if constexpr (std::is_same_v<Converter, T>) {
      return data <=> rhs.data;
    } else {
      return Converter::ToBase(data) <=> T::ToBase(rhs.data);
    }
  }

  constexpr auto operator==(Arithmetic auto rhs) const noexcept -> bool {
    return data == rhs;
  }

  template <class T, class R>
  constexpr auto operator==(const OtherBase<T, R>& rhs) const noexcept {
    if constexpr (std::is_same_v<Converter, T>) {
      return data == rhs.data;
    } else {
      return Converter::ToBase(data) == T::ToBase(rhs.data);
    }
  }

  Data data;
  [[no_unique_address]] Converter conv;

  // base += base
  constexpr auto operator+=(const Base&& rhs) noexcept -> auto& {
    data += rhs.data;
    return *this;
  }

  // base + base
  friend constexpr auto operator+(Base lhs, const Base&& rhs) noexcept {
    lhs += rhs;
    return lhs;
  }

  // base -= base
  constexpr auto operator-=(const Base&& rhs) noexcept -> auto& {
    data -= rhs.data;
    return *this;
  }

  // base - base
  friend constexpr auto operator-(Base lhs, const Base&& rhs) noexcept {
    lhs -= rhs;
    return lhs;
  }
};

}  // namespace csm_units
