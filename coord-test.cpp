#include <cstdlib>
#include <vector>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "coord.hpp"

TEST_CASE("Constructor and getters") {
  Coord a{1,3};
  CHECK(a.getX() == 1 and a.getY() == 3);
}