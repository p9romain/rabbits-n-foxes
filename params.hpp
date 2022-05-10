#ifndef PARAMS_HPP
#define PARAMS_HPP

#include <utility>

extern std::pair<int, int> GRIDSIZE ; // like (height, width)

extern float STEPPROB ;
extern float STEPJUNK ;

extern int ROUND ;
extern int ROUND_THRESHOLD ;

/* Fox */
extern float RATEFOX ;

extern std::pair<float, float> PROBBIRTH_FOX ;
extern std::pair<float, float> FINIT_FOX ;
extern std::pair<float, float> FREPROD_FOX ;
extern std::pair<float, float> FMAX_FOX ;

/* Rabbit */
extern float RATERABBIT ;

extern std::pair<float, float> PROBBIRTH_RABBIT ;
extern std::pair<float, float> FGIVEN_RABBIT ;
extern std::pair<int, int> MIN_RATEBIRTH_RABBIT ;

#endif