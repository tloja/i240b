#ifndef LINE_HH_
#define LINE_HH_

#include "point.hh"
#include <string>

struct Line {
  const Point& a, b;

  /** constructor */
  Line(const Point& a_in=Point(), const Point& b_in=Point()) : a(a_in), b(b_in) { };

  double length() const;

  /** return a string representation of this point */
  std::string toString() const;
};

#endif //ifndef LINE_HH_
