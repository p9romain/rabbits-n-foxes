#include <utility>

#include "params.hpp"

std::pair<int, int> GRIDSIZE = std::pair<int, int>(30,30) ; // like (height, width)

float STEPPROB = 0.01 ;
float STEPJUNK = 0.1 ;

int ROUND = 0 ;
int ROUND_THRESHOLD = -1 ;

/* Fox */
float RATEFOX = 0.07 ;

std::pair<float, float> PROBBIRTH_FOX = std::pair<float, float>(0.05,0.05) ;
std::pair<float, float> FINIT_FOX = std::pair<float, float>(5,5) ;
std::pair<float, float> FREPROD_FOX = std::pair<float, float>(8,8) ;
std::pair<float, float> FMAX_FOX = std::pair<float, float>(10,10) ;

/* Rabbit */
float RATERABBIT = 0.20 ;

std::pair<float, float> PROBBIRTH_RABBIT = std::pair<float, float>(0.30,0.30) ;
std::pair<float, float> FGIVEN_RABBIT = std::pair<float, float>(5,5) ;
std::pair<int, int> MIN_RATEBIRTH_RABBIT = std::pair<int, int>(4,4) ;