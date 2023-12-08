#include <doctest/doctest.h>

#include <csm_units/units.hpp>

#ifndef CSMUNITS_VALUE_TYPE
#define CSMUNITS_VALUE_TYPE double
#endif

namespace csm_units {

namespace concepts {

template <class T>
concept Operator = requires(T oper) {
  { T::num } -> std::convertible_to<int>;
  { T::den } -> std::convertible_to<int>;
  { oper | 1.0 } -> Arithmetic;
  { 1.0 | oper } -> Arithmetic;
  { T::Apply(1.0) } -> Arithmetic;
};

template <class T>
concept Converter = requires(T conv) {
  { T::FromSI(1.0) } -> Arithmetic;
  { T::ToSI(1.0) } -> Arithmetic;
};

template <class T>
concept Definition = requires(T def) {
  { typename T::E() } -> ExpType;
  { typename T::L() } -> Converter;
  { typename T::M() } -> Converter;
  { typename T::T() } -> Converter;
  { typename T::C() } -> Converter;
  { typename T::TP() } -> Converter;
  { typename T::A() } -> Converter;
  { typename T::LM() } -> Converter;
};

}  // namespace concepts

namespace converter {

namespace detail {

template <int N, int D>
struct Multiply {
  constexpr static int num = N;
  constexpr static int den = D;
  constexpr static auto Apply(Arithmetic auto data) { return data * N / D; }
};

template <int N, int D>
struct Divide {
  constexpr static int num = N;
  constexpr static int den = D;
  constexpr static auto Apply(Arithmetic auto data) { return data * D / N; }
};

template <int N, int D>
struct Add {
  constexpr static int num = N;
  constexpr static int den = D;
  constexpr static auto Apply(Arithmetic auto data) {
    return data + decltype(data)(N) / D;
  }
};

template <int N, int D>
struct Subtract {
  constexpr static int num = N;
  constexpr static int den = D;
  constexpr static auto Apply(Arithmetic auto data) {
    return data - decltype(data)(N) / D;
  }
};

}  // namespace detail

template <class BinOp>
struct Operator : public BinOp {
  constexpr friend auto operator|(Arithmetic auto lhs, Operator /*rhs*/) {
    return BinOp::Apply(lhs);
  }
  constexpr friend auto operator|(Operator /*lhs*/, Arithmetic auto rhs) {
    return BinOp::Apply(rhs);
  }
};

template <int N, int D = 1>
using Multiply = Operator<detail::Multiply<N, D>>;

template <int N, int D = 1>
using Divide = Operator<detail::Divide<N, D>>;

template <int N, int D = 1>
using Add = Operator<detail::Add<N, D>>;

template <int N, int D = 1>
using Subtract = Operator<detail::Subtract<N, D>>;

template <concepts::Operator... Ts>
struct Converter {
  constexpr static auto FromSI(Arithmetic auto data) {
    return (data | ... | Ts());
  }
  constexpr static auto ToSI(Arithmetic auto data) {
    return (typename Inverse<Ts>::val() | ... | data);
  }

 private:
  template <class T>
  struct Inverse {};

  template <int N, int D>
  struct Inverse<Multiply<N, D>> {
    using val = Divide<N, D>;
  };

  template <int N, int D>
  struct Inverse<Divide<N, D>> {
    using val = Multiply<N, D>;
  };

  template <int N, int D>
  struct Inverse<Add<N, D>> {
    using val = Subtract<N, D>;
  };

  template <int N, int D>
  struct Inverse<Subtract<N, D>> {
    using val = Add<N, D>;
  };
};

struct None {
  constexpr static auto FromSI(Arithmetic auto data) { return data; }
  constexpr static auto ToSI(Arithmetic auto data) { return data; }
};

template <concepts::Converter ConvL, concepts::Converter ConvR>
struct Selector {
  using val = ConvL;
};

template <concepts::Converter ConvL>
struct Selector<ConvL, None> {
  using val = ConvL;
};

template <concepts::Converter ConvR>
struct Selector<None, ConvR> {
  using val = ConvR;
};

template <>
struct Selector<None, None> {
  using val = None;
};

using Farenheit = Converter<Subtract<5463, 20>, Multiply<9, 5>, Add<32>>;

}  // namespace converter

namespace definition {

template <concepts::Definition Def, Arithmetic Data = CSMUNITS_VALUE_TYPE>
class Unit {
 public:
  constexpr Unit(double input) : data(input){};
  double data;
};

}  // namespace definition

template <ExpType Exp, concepts::Converter ConvL = converter::None,
          concepts::Converter ConvM = converter::None,
          concepts::Converter ConvT = converter::None,
          concepts::Converter ConvC = converter::None,
          concepts::Converter ConvTP = converter::None,
          concepts::Converter ConvA = converter::None,
          concepts::Converter ConvLM = converter::None>
class Definition {
 public:
  using E = Exp;
  using L = ConvL;
  using M = ConvM;
  using T = ConvT;
  using C = ConvC;
  using TP = ConvTP;
  using A = ConvA;
  using LM = ConvLM;

  constexpr friend auto operator*(Arithmetic auto lhs, Definition /*rhs*/) {
    return definition::Unit<Definition, decltype(lhs)>(lhs);
  }
  template <concepts::Definition D, Arithmetic Data>
  constexpr friend auto operator*(definition::Unit<D, Data> lhs,
                                  Definition /*rhs*/) {
    return definition::Unit<Multiply<D, Definition>, Data>(lhs.data);
  }
  constexpr friend auto operator/(Arithmetic auto lhs, Definition /*rhs*/) {
    return definition::Unit<Invert, decltype(lhs)>(lhs);
  }
  template <concepts::Definition D, Arithmetic Data>
  constexpr friend auto operator/(definition::Unit<D, Data> lhs,
                                  Definition /*rhs*/) {
    return definition::Unit<Divide<D, Definition>, Data>(lhs.data);
  }

 private:
  using Invert = Definition<ExponentsFlip<E>, ConvL, ConvM, ConvT, ConvC,
                            ConvTP, ConvA, ConvLM>;

  template <concepts::Definition A, concepts::Definition B>
  using Multiply = Definition<
      ExponentsAdd<typename A::E, typename B::E>,
      typename converter::Selector<typename A::L, typename B::L>::val,
      typename converter::Selector<typename A::M, typename B::M>::val,
      typename converter::Selector<typename A::T, typename B::T>::val,
      typename converter::Selector<typename A::C, typename B::C>::val,
      typename converter::Selector<typename A::TP, typename B::TP>::val,
      typename converter::Selector<typename A::A, typename B::A>::val,
      typename converter::Selector<typename A::LM, typename B::LM>::val>;

  template <concepts::Definition A, concepts::Definition B>
  using Divide = Definition<
      ExponentsSubtract<typename A::E, typename B::E>,
      typename converter::Selector<typename A::L, typename B::L>::val,
      typename converter::Selector<typename A::M, typename B::M>::val,
      typename converter::Selector<typename A::T, typename B::T>::val,
      typename converter::Selector<typename A::C, typename B::C>::val,
      typename converter::Selector<typename A::TP, typename B::TP>::val,
      typename converter::Selector<typename A::A, typename B::A>::val,
      typename converter::Selector<typename A::LM, typename B::LM>::val>;

  // TODO: return nondimnensional type when needed i.e. K / K
};

namespace definition {

using Farenheit =
    Definition<Exponents<0, 0, 0, 0, 1, 0, 0>, converter::None, converter::None,
               converter::None, converter::None, converter::Farenheit>;
using SquareFarenheit =
    Definition<Exponents<0, 0, 0, 0, 2, 0, 0>, converter::None, converter::None,
               converter::None, converter::None, converter::Farenheit>;

}  // namespace definition

constexpr auto F =  // NOLINT(readability-identifier-length)
    definition::Farenheit();

using Farenheit = definition::Unit<definition::Farenheit, double>;

}  // namespace csm_units

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

TEST_SUITE("Conversion Operators") {
  TEST_CASE("Multiply") {
    CHECK(converter::Multiply<3, 1>::Apply(5.5) == 16.5);
    CHECK(converter::Multiply<3, 5>::Apply(5) == 3);
  }

  TEST_CASE("Converter") {
    CHECK(converter::Farenheit::FromSI(300.0) == doctest::Approx(80.33));
    CHECK(converter::Farenheit::ToSI(300.0) == doctest::Approx(422.039));
  }

  TEST_CASE("Definition") {
    static_assert(
        std::is_same_v<definition::Unit<definition::Farenheit, double>,
                       decltype(1.0 * F)>);
    static_assert(
        std::is_same_v<definition::Unit<definition::SquareFarenheit, double>,
                       decltype(1.0 * F * F)>);
    static_assert(
        std::is_same_v<definition::Unit<definition::SquareFarenheit, double>,
                       decltype(Farenheit(1.0) * F)>);
  }
}

// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test