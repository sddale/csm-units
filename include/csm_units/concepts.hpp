/**  \file concepts.hpp
 *   \brief this file does this and that.
 *
 *   Typings more things.
 */

#pragma once

#include <concepts>
#include <cstdint>
#include <ratio>
#include <type_traits>

namespace csm_units {

/**
 * \brief This concept controls arithmetics
 */
template <class T>
concept Arithmetic = std::is_arithmetic_v<T>;

template <class T>
concept ExpType = requires(T) {
                    { T::L::num } -> std::convertible_to<intmax_t>;
                    { T::L::den } -> std::convertible_to<intmax_t>;
                    { T::M::num } -> std::convertible_to<intmax_t>;
                    { T::M::den } -> std::convertible_to<intmax_t>;
                    { T::T::num } -> std::convertible_to<intmax_t>;
                    { T::T::den } -> std::convertible_to<intmax_t>;
                    { T::C::num } -> std::convertible_to<intmax_t>;
                    { T::C::den } -> std::convertible_to<intmax_t>;
                    { T::TP::num } -> std::convertible_to<intmax_t>;
                    { T::TP::den } -> std::convertible_to<intmax_t>;
                    { T::A::num } -> std::convertible_to<intmax_t>;
                    { T::A::den } -> std::convertible_to<intmax_t>;
                    { T::LM::num } -> std::convertible_to<intmax_t>;
                    { T::LM::den } -> std::convertible_to<intmax_t>;
                  };

template <class T>
concept RatioType = requires(T) {
                      { T::num } -> std::convertible_to<intmax_t>;
                      { T::den } -> std::convertible_to<intmax_t>;
                    };

template <class T>
concept UnitBaseType = requires(T unitbase) {
                         { unitbase.data } -> std::convertible_to<double>;
                         { unitbase.Flip() };
                       };

template <class T>
concept UnitType = requires(T unit) {
                     { unit.data } -> std::convertible_to<double>;
                     // { unitbase.data } -> std::convertible_to<double>;
                     // { unitbase.Flip() };
                     { typename T::SI() };
                   };

}  // namespace csm_units