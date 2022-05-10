#include <ctime>
#include <iostream>
#include <vector>
#include <utility>

#include "utilities.hpp"
#include "coord.hpp"

float rng(float start, float end, float step) {
  return start + (rand() % (int((end - start) / step) + 1)) * step;
}

std::ostream& operator<<(std::ostream& out, std::pair<int, int> p) {
  return out << "(" << p.first << ", " << p.second << ")" ;
}

std::ostream& operator<<(std::ostream& out, std::pair<float, float> p) {
  return out << "(" << p.first << ", " << p.second << ")" ;
}