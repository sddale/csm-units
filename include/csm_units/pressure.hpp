#ifndef PRESSURE_H
#define PRESSURE_H

class Pressure {
 public:
  Pressure(double pressure) { this->pressure = pressure; }
  // constexpr double pressure; <- why does this not work?
  double pressure;  // Pa
};

#endif