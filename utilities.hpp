#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <iostream>
#include <vector>
#include <utility>

#include "coord.hpp"

float rng(float start, float end, float step) ;

std::ostream& operator<<(std::ostream& out, std::pair<int, int> p) ;
std::ostream& operator<<(std::ostream& out, std::pair<float, float> p) ;

#endif