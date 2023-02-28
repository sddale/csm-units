#pragma once

#include <concepts>
#include <type_traits>

namespace csm_units {

template <class T>
concept Arithmetic = std::is_arithmetic_v<T>;

template <class T>
concept ConverterType = requires(T t) {
                          { T::ToBase(0.0) } -> std::convertible_to<double>;
                          { T::FromBase(0.0) } -> std::convertible_to<double>;
                        };

template <class T>
concept BaseType = requires(T t) {
                     { t.data } -> std::convertible_to<double>;
                     {
                       t.conv.ToBase(0.0)
                       } -> std::convertible_to<decltype(t.data)>;
                     {
                       t.conv.FromBase(0.0)
                       } -> std::convertible_to<decltype(t.data)>;
                   };
}  // namespace csm_units