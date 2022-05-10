#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <vector>

#include "coord.hpp"

bool isIn(std::vector<Coord> l, Coord c);
bool operator==(std::vector<Coord> l, std::vector<Coord> m);

bool isIn(std::vector<Coord> l, Coord c) {
  for (auto a : l) {
    if (a == c) return true;
  }
  return false;
}

bool operator==(std::vector<Coord> l, std::vector<Coord> m) {
  if ( l.size() != m.size() ) return false;
  for (auto a : l) {
    if (not isIn(m, a)) return false;
  }
  return true;
}

TEST_CASE("Constructor and getters") {
  Coord a{1,3};
  Coord b{42};
  CHECK(a.getLine() == 1);
  CHECK(a.getColumn() == 3);
  CHECK(b.getLine() == 1);
  CHECK(b.getColumn() == 12);
}

TEST_CASE("Operators == and !=") {
  Coord a{1,3};
  Coord b{2,1};
  Coord c{2,6};

  CHECK(a != b);
  CHECK(a == a);
  CHECK(b == Coord{2,1});
  CHECK(b != c);
}

TEST_CASE("Get neighbors") {
  // Corners
  Coord ur{0,0};
  Coord ul{0,29};
  Coord dr{29,0};
  Coord dl{29,29};
  // Borders
  Coord u{0,15};
  Coord d{29,15};
  Coord l{15,0};
  Coord r{15,29};
  // Inside
  Coord a{10,10};

  CHECK( ur.getNeighbors() == std::vector<Coord>{{ Coord{0,1}, Coord{1,0}, Coord{1,1} }} ) ;
  CHECK( ul.getNeighbors() == std::vector<Coord>{{ Coord{0,28}, Coord{1,28}, Coord{1,29} }} ) ;
  CHECK( dr.getNeighbors() == std::vector<Coord>{{ Coord{28,0}, Coord{28,1}, Coord{29,1} }} ) ;
  CHECK( dl.getNeighbors() == std::vector<Coord>{{ Coord{28,28}, Coord{28,29}, Coord{29,28} }} ) ;

  CHECK( u.getNeighbors() == std::vector<Coord>{{ Coord{0,14}, Coord{0,16}, Coord{1,14}, Coord{1,15}, Coord{1,16} }} ) ;
  CHECK( d.getNeighbors() == std::vector<Coord>{{ Coord{28,14}, Coord{28,15}, Coord{28,16}, Coord{29,14}, Coord{29,16} }} ) ;
  CHECK( l.getNeighbors() == std::vector<Coord>{{ Coord{14,0}, Coord{14,1}, Coord{15,1}, Coord{16,0}, Coord{16,1} }} ) ;
  CHECK( r.getNeighbors() == std::vector<Coord>{{ Coord{14,28}, Coord{14,29}, Coord{15,28}, Coord{16,28}, Coord{16,29} }} ) ;

  CHECK( a.getNeighbors() == std::vector<Coord>{{ Coord{9,9}, Coord{9,10}, Coord{9,11}, Coord{10,9}, Coord{10,11}, Coord{11,9}, Coord{11,10}, Coord{11,11} }} ) ;
}

TEST_CASE("Method toInt") {
  // Works only if GRIDSIZE is in the format 30x30
  Coord a{1,3};
  Coord b{2,1};

  CHECK(a.toInt() == 33);
  CHECK(b.toInt() == 61);
}