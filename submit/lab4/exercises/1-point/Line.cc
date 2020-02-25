#include "Line.hh"
#include "point.hh"

#include <string>
#include <sstream>

double Line::length() const {
  return a.distance(b);
}

std::string Line::toString() const {
  std::stringstream s;
  s << a.toString() + " -- " << b.toString() +" length = " << length();
  return s.str();
}
