// #define DOCTEST_CONFIG_IMPLEMENT
// #include "doctest.h"

#include <ctime>

#include "linked_list.hpp"

#include "game.hpp"
#include "displaying.hpp"

int main() {
  /*doctest::Context context(argc, argv);
  int res = context.run();
  if (context.shouldExit()) return res;*/

  srand(time(NULL));

  Game g{} ;
  g.init() ;
  print(g.getGrid(), "game_test", 0) ;
  for ( int i = 1 ; i < 1000 ; i++ ) {
    g.moveAllRabbits();
    g.moveAllFoxes();
    print(g.getGrid(), "game_test", i);

    if( g.isTheEnd() )
    {
      break ;
    }
  }
}
