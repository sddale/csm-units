#pragma once

#include <concepts>
#include <cstdint>
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

template <class T>
concept ExpType = requires(T) {
                    { T::l_num } -> std::convertible_to<intmax_t>;
                    { T::l_den } -> std::convertible_to<intmax_t>;
                    { T::m_num } -> std::convertible_to<intmax_t>;
                    { T::m_den } -> std::convertible_to<intmax_t>;
                    { T::t_num } -> std::convertible_to<intmax_t>;
                    { T::t_den } -> std::convertible_to<intmax_t>;
                  };

}  // namespace csm_units