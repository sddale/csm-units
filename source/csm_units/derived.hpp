#include <ratio>

template <class Length, int LengthPower, class Mass, int MassPower, class Time,
          int TimePower, Arithmetic Data = double>
class Derived {
 public:
  Data data;
}