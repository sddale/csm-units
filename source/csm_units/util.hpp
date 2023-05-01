#pragma once

#include <algorithm>

namespace csm_units {

template <size_t N>
// NOLINTBEGIN(modernize-avoid-c-arrays)
struct StringLiteral {
  constexpr explicit(false) StringLiteral(const char (&str)[N]) {
    std::copy_n(str, N, value);
  }

  char value[N];
};
// NOLINTEND(modernize-avoid-c-arrays)

}  // namespace csm_units