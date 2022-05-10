#include <stdexcept>
#include <string>

#include "utilities.hpp"
#include "params.hpp"

#include "animal.hpp"

/* Animal */
// Getter
float Animal::getProbBirth() const
{
  return this->probBirth ;
}

std::string Animal::getType() const
{
  return this->type ;
}

// Constructors
Animal::Animal( std::string type, float probBirth ) : type{type}, probBirth{probBirth} {}


/* Fox */

// Constructors
Fox::Fox(): Animal("Fox", rng(PROBBIRTH_FOX.first, PROBBIRTH_FOX.second, STEPPROB)),
            fInit{rng(FINIT_FOX.first, FINIT_FOX.second, STEPJUNK)},
            fReprod{rng(FREPROD_FOX.first, FREPROD_FOX.second, STEPJUNK)},
            fMax{rng(FMAX_FOX.first, FMAX_FOX.second, STEPJUNK)},
            food{fInit} {}

// Setter
void Fox::setFood( const float f )
{
  if ( f < 0 )
  {
    this->food = 0 ;
  }
  else if ( f > this->fMax )
  {
    this->food = this->fMax ;
  }
  else
  {
    this->food = f ;
  }
}


// Getter
float Fox::getFood() const
{
  return this->food ;
}


// Methods
bool Fox::isDead() const
{
  return this->food == 0 ;
}

bool Fox::canGiveBirth() const
{
  return this->food >= this->fReprod ;
}

bool Fox::reachFoodMax() const
{
  return this->food == this->fMax ;
}



/* Rabbit */
// Getter
float Rabbit::getfGiven() const
{
  return fGiven ;
}

int Rabbit::getMinRateBirth() const
{
  return minRateBirth ;
}


// Constructors
Rabbit::Rabbit(): Animal("Rabbit", rng(PROBBIRTH_RABBIT.first, PROBBIRTH_RABBIT.second, STEPPROB)),
                  fGiven{rng(FGIVEN_RABBIT.first, FGIVEN_RABBIT.second, STEPJUNK)},
                  minRateBirth{int(rng(MIN_RATEBIRTH_RABBIT.first, MIN_RATEBIRTH_RABBIT.second, STEPJUNK))} {}


// Virtual
// Fox
void Animal::setFood( const float f ) {}
float Animal::getFood() const { return 0 ; }
bool Animal::isDead() const { return false ; }
bool Animal::canGiveBirth() const { return false ; }
bool Animal::reachFoodMax() const { return false ; }

// Rabbit
float Animal::getfGiven() const { return 0 ; }
int Animal::getMinRateBirth() const { return 0 ; }