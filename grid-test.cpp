#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>

#include "grid.hpp"
#include "coord.hpp"
#include "animal.hpp"

TEST_CASE("Grid")
{
  Grid grid = Grid() ;
  Coord c{1,0} ;
  Coord C{0,5} ;

  Rabbit* r = (Rabbit*) malloc(sizeof(Rabbit)) ;
  Fox* f = (Fox*) malloc(sizeof(Fox)) ;
  grid.setCell(c, r) ;
  grid.setCell(5, f) ;

  SUBCASE("Getters")
  {
    CHECK_THROWS_AS( grid.getCell(0), std::invalid_argument ) ;
    CHECK( grid.getCell(c) == r ) ;
    CHECK( grid.getCell(c) == grid.getCell(30) ) ;
    CHECK( grid.getCellId(c) == 30 ) ;
    CHECK( grid.getCell(C) == f ) ;
  }

  SUBCASE("Setters")
  {
    CHECK( grid.getCell(c) == r ) ;
    CHECK( grid.getCell(C) == f ) ;
  }

  SUBCASE("Boolean test")
  {
    Coord t{0,0} ;

    CHECK( grid.isCellEmpty(0) ) ;
    CHECK( grid.isCellEmpty(t) ) ;
    CHECK_FALSE( grid.isCellEmpty(c) ) ;
    CHECK_FALSE( grid.isCellEmpty(30) ) ;
    CHECK_FALSE( grid.isCellEmpty(C) ) ;
    CHECK_FALSE( grid.isCellEmpty(5) ) ;
  }

  SUBCASE("Freedom youhou")
  {
    CHECK_FALSE( grid.isCellEmpty(c) ) ;
    CHECK_FALSE( grid.isCellEmpty(C) ) ;

    grid.freeCell(c) ;
    grid.freeCell(C) ;

    CHECK( grid.isCellEmpty(c) ) ;
    CHECK( grid.isCellEmpty(C) ) ;
  }
}