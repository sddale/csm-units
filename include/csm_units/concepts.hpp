#pragma once

#include <concepts>
#include <cstdint>
#include <ratio>
#include <type_traits>

namespace csm_units {

template <class T>
concept Arithmetic = std::is_arithmetic_v<T>;

template <class T>
concept ConverterType = requires(T base) {
                          { T::ToBase(0.0, 1) } -> std::convertible_to<double>;
                          {
                            T::FromBase(0.0, 1)
                            } -> std::convertible_to<double>;
                        };

template <class T>
concept BaseType = requires(T base) {
                     { base.data } -> std::convertible_to<double>;
                     {
                       std::remove_reference_t<T>::ToBase(0.0)
                       } -> std::convertible_to<decltype(base.data)>;
                     {
                       std::remove_reference_t<T>::FromBase(0.0)
                       } -> std::convertible_to<decltype(base.data)>;
                   };

template <class T>
concept ExpType = requires(T) {
                    { T::L::num } -> std::convertible_to<intmax_t>;
                    { T::L::den } -> std::convertible_to<intmax_t>;
                    { T::M::num } -> std::convertible_to<intmax_t>;
                    { T::M::den } -> std::convertible_to<intmax_t>;
                    { T::T::num } -> std::convertible_to<intmax_t>;
                    { T::T::den } -> std::convertible_to<intmax_t>;
                  };

template <class T>
concept RatioType = requires(T) {
                      { T::num } -> std::convertible_to<intmax_t>;
                      { T::den } -> std::convertible_to<intmax_t>;
                    };

}  // namespace csm_units