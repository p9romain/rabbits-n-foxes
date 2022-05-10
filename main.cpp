#include <vector>
#include <iostream>
#include <string>
#include <utility>

#include "params.hpp"
#include "linked_list.hpp"
#include "utilities.hpp"

#include "game.hpp"
#include "displaying.hpp"

bool isIn( auto x, std::vector<auto> v )
{
  for ( auto a : v )
  {
    if ( x == a )
    {
      return true ;
    }
  }
  return false ;
}

int main(int argc, char **argv)
{
  std::vector<std::string> YES = {{ "yes", "y", "oui", "o" }} ;
  std::vector<std::string> NO = {{ "no", "n", "non" }} ;

  bool pr, display, params ;
  std::string str ;

  do
  {
    std::cout << "Before starting the game, would you like to see the game in the terminal ?" << std::endl ;
    std::cout << "(enter yes/y/oui/o or no/n/non, all in lowercase). " ;
    std::cin >> str ;
  } 
  while ( not isIn(str, YES) and not isIn(str, NO) ) ;

  display = isIn(str, YES) ? true : false ;

  std::cout << std::endl ;

  do
  {
    std::cout << "Also, would you like to see the game in a gif ?" << std::endl ;
    std::cout << "(enter yes/y/oui/o or no/n/non, all in lowercase). " ;
    std::cin >> str ;
  } 
  while ( not isIn(str, YES) and not isIn(str, NO) ) ;

  pr = isIn(str, YES) ? true : false ;

  std::cout << std::endl ;

  if ( not pr and not display )
  {
    std::cout << "If you don't want to see the game, then bye ! " << std::endl ;
    std::cout << std::endl ;
    return 0 ;
  }

  std::cout << std::string(GRIDSIZE.second+2, '=') << std::endl ;

  std::cout << "Welcome to the game ! You'll see a population of foxes and rabbits living together in a grid. For the first frame, and for the progress, we need some basic parameters." << std::endl ;

  do
  {
    std::cout << "Would you like to enter your own grid size?" << std::endl ;
    std::cout << "(enter yes/y/oui/o or no/n/non, all in lowercase). " ;
    std::cin >> str ;
  } 
  while ( not isIn(str, YES) and not isIn(str, NO) ) ;

  params = isIn(str, YES) ? true : false ;

  if ( params )
  {
    do
      {
        std::cout << "What is the size of the grid ? (height x width)" << std::endl ;
        std::cout << "The values must be positive integers. " ;
        std::cin >> GRIDSIZE.first >> GRIDSIZE.second ;
      } while ( GRIDSIZE.first < 0 or GRIDSIZE.second < 0 ) ;
  }

  std::cout << std::endl ;

  std::cout << "If a game is taking too much time, you can give a threshold. (default is -1 for None)" << std::endl ;
  std::cout << "It must be an int. " ;
  std::cin >> ROUND_THRESHOLD ;

  std::cout << std::endl ;

  do
  {
    std::cout << "Would you like to enter your own parameters ?" << std::endl ;
    std::cout << "(enter yes/y/oui/o or no/n/non, all in lowercase). " ;
    std::cin >> str ;
  } 
  while ( not isIn(str, YES) and not isIn(str, NO) ) ;

  params = isIn(str, YES) ? true : false ;

  std::cout << std::endl ;

  if ( params )
  {
    std::cout << "For each parameters, you need to enter two value separated by a space : they will be the range of each parameters (except for the steps and the rates)" << std::endl ;

    do
    {
      std::cout << "What is the differents steps for the probabilities and other stuffs ?" << std::endl ;
      std::cout << "The values must be positive floats, and the step for the probabilities need te be between 0 and 1. " ;
      std::cin >> STEPPROB >> STEPJUNK ;
    } while ( STEPPROB < 0 or STEPPROB > 1 or STEPJUNK < 0 ) ;

    std::cout << std::endl ;

    do
    {
      std::cout << "What is the ratio of Foxes and of Rabbits ?" << std::endl ;
      std::cout << "The values must be floats between 0 and 1. " ;
      std::cin >> RATEFOX >> RATERABBIT ;
    } while ( RATEFOX < 0 or RATERABBIT < 0 or RATEFOX > 1 or RATERABBIT > 1 ) ;

    std::cout << std::endl ;

    do
    {
      std::cout << "What is the probability for a Fox to give birth ?" << std::endl ;
      std::cout << "The values must be floats between 0 and 1, and the second value must be bigger or equal to the first one. " ;
      std::cin >> PROBBIRTH_FOX.first >> PROBBIRTH_FOX.second ;
    } while ( PROBBIRTH_FOX.first < 0 or PROBBIRTH_FOX.second < 0 or PROBBIRTH_FOX.first > 1 or PROBBIRTH_FOX.second > 1 or PROBBIRTH_FOX.first > PROBBIRTH_FOX.second ) ;

    std::cout << std::endl ;

    do
    {
      std::cout << "What is the maximum food value for a Fox ?" << std::endl ;
      std::cout << "The values must positive integers, and the second value must be bigger or equal to the first one. " ;
      std::cin >> FMAX_FOX.first >> FMAX_FOX.second ;
    } while ( FMAX_FOX.first < 0 or FMAX_FOX.second < 0 or FMAX_FOX.first > FMAX_FOX.second ) ;

    std::cout << std::endl ;

    do
    {
      std::cout << "What is the initial food for a Fox ?" << std::endl ;
      std::cout << "The values must positive integers, and the second value must be bigger or equal to the first one." << std::endl ;
      std::cout << "Also, it must be less or equal to your maximum value (for security, the second value must be less than the first value of the maximum)." << std::endl ;
      std::cout << "Here's your maximum values : " << FMAX_FOX << ". " ;
      std::cin >> FINIT_FOX.first >> FINIT_FOX.second ;
    } while ( FINIT_FOX.first < 0 or FINIT_FOX.second < 0 or FINIT_FOX.first > FINIT_FOX.second or FINIT_FOX.second > FMAX_FOX.first ) ;

    std::cout << std::endl ;

    do
    {
      std::cout << "What is the food threshold so that a Fox can give birth ?" << std::endl ;
      std::cout << "The values must positive integers, and the second value must be bigger or equal to the first one." << std::endl ;
      std::cout << "Also, it must be less or equal to your maximum value (for security, the second value must be less than the first value of the maximum)." << std::endl ;
      std::cout << "Here's your maximum values : " << FMAX_FOX << ". " ;
      std::cin >> FREPROD_FOX.first >> FREPROD_FOX.second ;
    } while ( FREPROD_FOX.first < 0 or FREPROD_FOX.second < 0 or FREPROD_FOX.first > FREPROD_FOX.second or FREPROD_FOX.second > FMAX_FOX.first ) ;

    std::cout << std::endl ;

    do
    {
      std::cout << "What is the probability for a Rabbit to give birth ?" << std::endl ;
      std::cout << "The values must be floats between 0 and 1, and the second value must be bigger or equal to the first one. " ;
      std::cin >> PROBBIRTH_RABBIT.first >> PROBBIRTH_RABBIT.second ;
    } while ( PROBBIRTH_RABBIT.first < 0 or PROBBIRTH_RABBIT.second < 0 or PROBBIRTH_RABBIT.first > 1 or PROBBIRTH_RABBIT.second > 1 or PROBBIRTH_RABBIT.first > PROBBIRTH_RABBIT.second ) ;

    std::cout << std::endl ;

    do
    {
      std::cout << "What is the food value given to a Fox when the Rabbit is being eaten ?" << std::endl ;
      std::cout << "The values must positive floats, and the second value must be bigger or equal to the first one. " ;
      std::cin >> FGIVEN_RABBIT.first >> FGIVEN_RABBIT.second ;
    } while ( FGIVEN_RABBIT.first < 0 or FGIVEN_RABBIT.second < 0 or FGIVEN_RABBIT.first > FGIVEN_RABBIT.second ) ;

    std::cout << std::endl ;

    do
    {
      std::cout << "What is the minimum needed number of empty neighbor cells so that a Rabbit can give birth ?" << std::endl ;
      std::cout << "The values must integers between 0 and 8, and the second value must be bigger or equal to the first one. " ;
      std::cin >> MIN_RATEBIRTH_RABBIT.first >> MIN_RATEBIRTH_RABBIT.second ;
    } while ( MIN_RATEBIRTH_RABBIT.first < 0 or MIN_RATEBIRTH_RABBIT.second < 0 or MIN_RATEBIRTH_RABBIT.first > 8 or MIN_RATEBIRTH_RABBIT.second > 8 or MIN_RATEBIRTH_RABBIT.first > MIN_RATEBIRTH_RABBIT.second ) ;

    std::cout << std::endl ;

    std::cout << std::string(GRIDSIZE.second+2, '-') << std::endl ;

    std::cout << "Here's your parameters :" << std::endl ;
      std::cout << "Size of the grid : " << GRIDSIZE << std::endl ;
      std::cout << "Step for the probabilities : " << STEPPROB << std::endl ;
      std::cout << "Step for the other stuffs : " << STEPJUNK << std::endl ;
      std::cout << std::endl ;
      std::cout << "* Foxes " << std::endl ;
        std::cout << "  - Proportion in the grid : " << RATEFOX << std::endl ;
        std::cout << "  - Inital food at birth : " << FINIT_FOX << std::endl ;
        std::cout << "  - Food threshold to give birth : " << FREPROD_FOX << std::endl ;
        std::cout << "  - Maximum food threshold : " << FMAX_FOX << std::endl ;
        std::cout << "  - Probability to give birth : " << PROBBIRTH_FOX << std::endl ;
      std::cout << std::endl ;
      std::cout << "* Rabbits " << std::endl ;
        std::cout << "  - Proportion in the grid : " << RATERABBIT << std::endl ;
        std::cout << "  - Food given to a fox when being eaten : " << FGIVEN_RABBIT << std::endl ;
        std::cout << "  - Number of empty neighbor cells needed to give birth : " << MIN_RATEBIRTH_RABBIT << std::endl ;
        std::cout << "  - Probability to give birth : " << PROBBIRTH_RABBIT << std::endl ;
  }
  else
  {
    std::cout << "Here's the default parameters (same values for the two bounds) :" << std::endl ;
      std::cout << "Size of the grid : " << GRIDSIZE << std::endl ;
      std::cout << std::endl ;
      std::cout << "* Foxes " << std::endl ;
        std::cout << "  - Proportion in the grid : " << RATEFOX << std::endl ;
        std::cout << "  - Inital food at birth : " << FINIT_FOX.first << std::endl ;
        std::cout << "  - Food threshold to give birth : " << FREPROD_FOX.first << std::endl ;
        std::cout << "  - Maximum food threshold : " << FMAX_FOX.first << std::endl ;
        std::cout << "  - Probability to give birth : " << PROBBIRTH_FOX.first << std::endl ;
      std::cout << std::endl ;
      std::cout << "* Rabbits " << std::endl ;
        std::cout << "  - Proportion in the grid : " << RATERABBIT << std::endl ;
        std::cout << "  - Food given to a fox when being eaten : " << FGIVEN_RABBIT.first << std::endl ;
        std::cout << "  - Number of empty neighbor cells needed to give birth : " << MIN_RATEBIRTH_RABBIT.first << std::endl ;
        std::cout << "  - Probability to give birth : " << PROBBIRTH_RABBIT.first << std::endl ;
  }

  std::cout << std::endl ;

  do
  {
    std::cout << "Start the game ? " ;
    std::cin >> str ;
  } while ( not isIn(str, YES) and not isIn(str, NO) ) ;

  if ( isIn(str, NO) )
  {
    std::cout << "Then bye !" << std::endl ;
    std::cout << std::endl ;
    return 0 ;
  }

  Game g{} ;

  do
  {
    if ( ROUND == 0 )
    {
      g.init() ;
    }
    else
    {
      g.moveAllRabbits() ;
      g.moveAllFoxes() ;
    }

    if ( pr )
    {
      print(g.getGrid(), "frame", ROUND) ;
    }
    if ( display )
    {
      std::cout << g << std::endl ;
    }

    ROUND++ ;
  }
  while( not g.isTheEnd() ) ;

  std::cout << "End of the game ! See you soon" << std::endl ;
  std::cout << std::endl ;
  return 0 ;
}