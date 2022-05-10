#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "animal.hpp"

TEST_CASE("Animal")
{
  Animal a{"Animal",0.56} ;
  CHECK( a.getProbBirth() == 0.56f ) ;
  CHECK( a.getType() == "Animal" ) ;
}

TEST_CASE("Fox")
{
  Fox f{} ;

  SUBCASE("Constructors and getters")
  {
    CHECK( f.getProbBirth() == 0.05f ) ; 
    CHECK( f.getFood() == 5 ) ;
  }
  SUBCASE("Setters")
  {
    f.setFood(5) ;
    CHECK( f.getFood() == 5 ) ;
  }
  SUBCASE("Death")
  {
    CHECK_FALSE( f.isDead() ) ;
    f.setFood(0) ;
    CHECK( f.isDead() ) ;
  }
  SUBCASE("Birth")
  {
    CHECK_FALSE( f.canGiveBirth() ) ;
    f.setFood(10) ;
    CHECK( f.canGiveBirth() ) ;
  }
  SUBCASE("Food Max")
  {
    CHECK_FALSE( f.reachFoodMax() ) ;
    f.setFood(10) ;
    CHECK( f.reachFoodMax() ) ;
  }
}

TEST_CASE("Rabbit")
{
  Rabbit r{} ;

  SUBCASE("Constructors and getters")
  {
    CHECK( r.getProbBirth() == 0.30f ) ;
    CHECK( r.getfGiven() == 5 ) ; 
    CHECK( r.getMinRateBirth() == 4 ) ; 
  }
}