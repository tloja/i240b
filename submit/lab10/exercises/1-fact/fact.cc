#include "fact.hh"

unsigned fact(unsigned n) {
  return n > 1 ? fact(n - 1)*n : 1;
}
