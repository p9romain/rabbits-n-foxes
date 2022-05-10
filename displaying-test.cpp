#include "displaying.hpp"
#include "game.hpp"

int main()
{
  Game g{} ;
  g.init() ;
  print(g.getGrid(), "displaying_test", 0) ;

  return 0 ;
}